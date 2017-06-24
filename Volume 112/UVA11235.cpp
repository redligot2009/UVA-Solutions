#include <bits/stdc++.h>
using namespace std;
//I struggled with this problem for so long.
//For the sake of myself and others, I have commented my solution
//with an explanation of why things are like that.
//Because this took way too long to even wrap my head around.
//-redligot2009

//Input array size
int N;
//Input array
int A[100000+1];

//Below: frequency count of all unique values, 
//and the positions of the first occurence of each value.
//(Both of these were kept track of through the use of unordered_maps)

//Reason I chose unordered_map is because the only operations I perform on 
//them is accessing, setting of values, and clearing them.
//Regular map requires O(log n) time in order to retrieve/set values,
//while unordered_map only requires O(1) time for retrieving or setting values.
//(pretty neat optimization imo. Gotta love unordered_maps <3)

//frequency count of a value
unordered_map<int,int> freq;
//position of the first occurence of a value
unordered_map<int,int> start;

//Here's a simple segment tree implementation that doesn't use a binary heap

//Segment tree node
struct tree
{
	//start position and end position respectively of the segment
	int i, j;
	//left node
	tree* left;
	//right node
	tree* right;
	//largest frequency
	int freq = 0;
	//constructor
	tree(int i, int j)
	{
		//initialize values
		this->i = i;
		this->j = j;
		//left and right nodes are null at the beginning
		left = right = NULL;
	}
	//getting the max frequency
	int query(int I, int J)
	{
		if(j < I||i > J)
		{
			//if position of node is out of bounds
			return -1;
		}
		if(i >= I && j <= J)
		{
			//if position of node is within bounds
			return freq;
		}
		//otherwise
		int v1 = left->query(I,J);
		//query on left
		int v2 = right->query(I,J);
		//query on right
		int ret;
		if( v1 == -1 ) ret = v2;//if left is out of bounds
		if( v2 == -1 ) ret = v1;//if right is out of bounds
		if( v1 >= v2 ) ret = v1;//if left is greater than right
		else ret = v2;//otherwise
		return ret;//return max frequency
	}
};

//Method for constructing the segment tree
tree* construct(int I, int J)
{
	if(I == J)
	{
		//if start and end positions are the same
		//i.e. the node pertains to only one element in the array
		tree* ret = new tree(I,J);
		ret->freq = freq[A[I]];
		return ret;
	}
	else
	{
		//if start and end positions not the same 
		//i.e. it pertains to multiple elements in the array
		//get midpoint
		int mid = (I+J)/2;
		//construct left tree
		tree* left = construct(I,mid);
		//construct right tree
		tree* right = construct(mid+1,J);
		//construct parent tree
		tree* ret = new tree(I,J);
		//set left tree
		ret->left = left;
		//set right tree
		ret->right = right;
		//get the greater frequency of the two
		ret->freq = max(right->freq,left->freq);
		//return greater frequency
		return ret;
	}
}

//root of segment tree
tree* root;

int main() {
	//who doesn't love some nice input optimization? <3
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> N)
	{
		if(N == 0)
		{
			//end if N is 0
			break;
		}
		int Q;
		cin >> Q;
		//clear freq and start maps
		freq.clear();
		start.clear();
		for(int i = 0; i < N; i ++)
		{
			cin >> A[i];
			//increment frequency of value of A[i]
			freq[A[i]] ++;
			//if first occurence
			if(freq[A[i]] == 1)
			{
				//set start[A[i]] to be the position of the 
				//first occurence of A[i].
				start[A[i]] = i;
			}
		}
		//construct the segment tree
		root = construct(0,N-1);
		while(Q--)
		{
			//i is start position
			//j is end position
			int i, j;
			cin >> i >> j;
			//subtract because array is 0-based
			i--;
			j--;
			//Because the input is given in increasing order,
			//it is not possible for a different element to exist within 
			//the range of i to j if the elements at those positions are
			//the same.
			if(A[i] == A[j])
			{
				//Therefore, if the elements at i and j are the same,
				//the frequency of the elements from i to j is
				//simply j(end position) - i(start position) + 1
				cout << j-i+1 << endl;
				continue;
			}
			//otherwise, continue on to next conditions
			
			//Answer stored here
			int ans;
			
			int v1 = freq[A[i]] - abs(start[A[i]]-i);
			//v1 is freq[A[i]] - abs(i - start[A[i]]).
			//In turn you end up getting the number of occurences of A[i]
			//within the given range.
			//The reason for this is because of the nice property of all 
			//elements in the input array being in increasing order.
			//This means that if we get abs(start[A[i]]-i), we get how many
			//A[i] is removed from freq[A[i]] in order to get the number of
			//occurences of A[i] from i to j;
			
			int v2 = (j - start[A[j]]) + 1;
			//v2 is (j - start[A[j]]) + 1
			//In turn you end up getting the number of occurences of A[j] 
			//within the given range.
			//The reason for this is also because of the nice property of 
			//all elements in the array being given in increasing order,
			//which makes it impossible for a different value to pop up within
			//the range of start[A[j]] to j. 
			//(j-start[A[j]]) is simply the difference between the end position,
			//and the position of the first occurence of A[j], and adding 1 to this
			//gives us the amount of occurences of A[j] between the range of i to j.
			//It will always be at least 1
			
			//If # of occurences of A[i] > # of occurences of A[j]
			if(v1 > v2)
			{
				//ans = # of occurences of A[i]
				ans = v1;
			}
			else
			{
				//ans = # of occurences of A[j]
				ans = v2;
			}
			//But wait, it's not finished yet!
			//What if the value with the greatest frequency within range i to j
			//is not the value of element at i or element at j?
			
			//r1 is the position of the last occurence of A[i]
			int r1 = start[A[i]] + freq[A[i]];
			//r2 is the position of the first occurence of A[j] - 1
			int r2 = start[A[j]] - 1;
			//basically if there is space in between not considered by
			//the cases above, then perform the query function of the segment tree
			//from range r1 to r2 in order to get the max frequency among the different
			//values from that space in between r1 and r2.
			if(r1 <= r2)
			{
				int val = root->query(r1,r2);
				if(val > ans)
				{
					//If this value is greater than the answer thus far, set it 
					//to be the new answer.
					//Basically if there is a new greater frequency in between the
					//space between, set that to be the new answer
					ans = val;
				}
			}
			//print answer
			cout << ans << endl;
		}
	}
	
	return 0;
}
//And that's it folks
//This problem was such a headache.
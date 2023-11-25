
#include<bits/stdc++.h>

using namespace std;

int binarysearch(vector<int> &a , int target) {
    for (int i=0 ; i<a.size() ; i++) {
    	if (a[i]==target) {
    		return i;
		}
	}
	return -1;
}

int main(void) {

	int n;
	cout<<"Enter the lenght of reference string - ";
	cin>>n;

	vector<int> ref(n);
    unordered_map<int,int> countmap;

	cout<<"Enter the reference string: ";
	for (int i=0 ;  i<n ; i++) {
		cin>>ref[i];
		countmap[ref[i]]++;
	}

	cout << "Enter the number of frames: ";
	cin>>n;

	vector<int> frames(n,-1);
	int pagefault = 0, full = 0, index = 0;

	for (int i=0; i<ref.size(); i++) {
		int check=binarysearch(frames,ref[i]);
		if (check<0) {
			pagefault++;
			if (full) {
				int min = INT_MAX, minindex = 0;
				for (int j=0; j<frames.size(); j++) {
					if(countmap[frames[j]]<min) {
						min=countmap[frames[j]];
						minindex=j;
					}
				}
				frames.erase(frames.begin()+minindex);
				frames.push_back(ref[i]);
			} else {
				frames[index++]=ref[i];
				if (index==frames.size()) {
					full=1;
				}
			}
		}
		countmap[ref[i]]--;
	}

	cout << "number of page faults = " << pagefault << endl;
	
    return 0;
}
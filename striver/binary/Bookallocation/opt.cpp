/*Input Format: n = 4, m = 2, arr[] = {12, 34, 67, 90}
Result: 113
Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.
*/
#include <bits/stdc++.h>
using namespace std;

int count_pages(vector<int>& book,int pages){           //we take pages input for calc its distr;func to count pages of book for n student distr
    int n=book.size();
    int stud=1;                         //counter to count n.o of students it has to be returned
    long long stpages=0;                //stores the  no. of pages to reach the pages taken from the loop
    for(int i=0;i<n;i++){               //going through array
        if(stpages+book[i]<=pages){           //we check if it is less than the pages
            stpages+=book[i];                   //add the book pages to the stpages
        }else{                              //else we reached  the pages and have to assign to new student
            stud++;                         //we inc the stud count as the pages are filled 
            stpages=book[i];                //we start filling pages a new
        }
    }return stud;                           //return the no of students
}
//function to get the minm no of pages in books a stud can get
int opt(vector<int>& book,int stud){
    if(stud>book.size()) return -1;         //if the no of stud are greater than books it will be invalid
    int low=*max_element(book.begin(),book.end());      //the mim value of pages will always be the max of array
    int high=accumulate(book.begin(),book.end(),0);     //whereas the sum is the maxm limit the total pages can go
    while(low<=high){                   //binary search;low will give te answer
        int mid=(low+high)/2;              //it is the pages we go by;mid to dhorten the search space
        int st=count_pages(book,mid);       //store the value from func in st
        if(st>stud) low=mid+1;              //if the n.o of st from func is more than stud it means we have to go for higher value
        else high=mid-1;                //else if the st is lower we go for lower values
    }return low;                        //we minimize the search space till the low stores the ans
}
int main(){
    vector<int> book={12, 34, 67, 90};
    int stud=2; 
    int ans=opt(book,stud);
    cout<<ans;
}
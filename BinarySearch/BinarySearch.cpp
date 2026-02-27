// problem : Binary search
// Level : easy
// Time complexity : O(log n)
// space complexity : O(1)

int binary_search(int data,int length, int a[]){

    int left= 0;
    int right=length-1;
    int mid;


    while(left<right){

        mid= floor((left+right)/2);

        if(a[mid]==data){
            return mid;
        }
        else if(data>a[mid]){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
        
    }
    return -1;

}

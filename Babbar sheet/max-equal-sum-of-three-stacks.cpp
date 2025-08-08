int maxEqualSum(int N1,int N2,int N3,
                vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int ans = 0;
        int sum1 = 0, sum2= 0, sum3 = 0;

        //Find out sum of all elements of the stack. Do this for all 3 stacks.
        for(int i=0; i<N1; i++) sum1 = sum1 + S1[i];
        for(int i=0; i<N2; i++) sum2 = sum2 + S2[i];
        for(int i=0; i<N3; i++) sum3 = sum3 + S3[i];

        int index1 = 0, index2 = 0, index3 = 0;
        while(true){
            if(index1==N1 or index2==N2 or index3==N3){
                ans = 0;
                break;
            }else if(sum1==sum2 and sum2==sum3){
                ans = sum1;
                break;
            }else if(sum1>=sum2 and sum1>=sum3){
                sum1 = sum1 - S1[index1++];
            }else if(sum2>=sum1 and sum2>=sum3){
                sum2 = sum2 - S2[index2++];
            }else{
                sum3 = sum3 - S3[index3++];
            }
        }
        return ans;
}
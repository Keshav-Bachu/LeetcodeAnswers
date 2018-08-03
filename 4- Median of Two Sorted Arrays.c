double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    
    
    //int *arr3 = (int * ) malloc(sizeof(int  * (nums1Size + nums2Size)));

    double returner;
    int * arr3 = (int *) malloc(sizeof(int) * (nums1Size + nums2Size));
    int isCounter = ((nums1Size + nums2Size) + 1)/2;
    int isODD = (nums1Size + nums2Size)%2;
    if(isODD == 0)
    {
        isCounter++;
    }
   // int lastIncrimented = 0;
  //  int lastBefore;
    
    if(nums1Size == 0 && nums2Size == 0)
    {
        return 0;
    }
    
    if(nums1Size == 1 && nums2Size == 1)
    {
        returner = nums2[0] + nums1[0];
        returner /= 2;
        return returner;
    }
    
    if(nums1Size == 0)
    {
        if(isODD == 1)
        {
            return nums2[nums2Size/2];
        }
        returner = nums2[nums2Size/2 - 1] + nums2[nums2Size/2];
        returner /= 2;
        return returner;
    }
    if(nums2Size == 0)
    {
        if(isODD == 1)
        {
            return nums1[nums1Size/2];
        }
        returner = nums1[nums1Size/2] + nums1[nums1Size/2 - 1];
        returner /= 2;
        return returner;
    }
    
    int count1, count2,count3;
    for(count1 = 0, count2 = 0,count3 = 0;  (count3) < isCounter && count1 < nums1Size && count2 < nums2Size; count3++)
    {
        if(nums1[count1] >= nums2[count2])
        {
            arr3[count3] = nums2[count2];
            count2++;
            
        }
        else if(nums1[count1] < nums2[count2])
        {
            arr3[count3] = nums1[count1];
            count1++;
        }        
    }
    
    if(count3 < isCounter && count1 < nums1Size)
    {
        while(count3 < isCounter)
        {
            arr3[count3] = nums1[count1++];
            count3++;
        }
        
    }
    if(count3 < isCounter && count2 < nums2Size)
    {
        while(count3 < isCounter)
        {
            arr3[count3] = nums2[count2++];
            count3++;
        }
        
    }
    if(isODD == 1)
    {
        printf("count3 = %d\n",nums1Size);
        return arr3[count3 - 1];
    }
    
    returner = arr3[count3 - 2] + arr3[count3 - 1];
    returner /= 2;
    return returner;
    
    
   /* if(isODD == 1)
    {
        
        
    }
    
    */
    
}

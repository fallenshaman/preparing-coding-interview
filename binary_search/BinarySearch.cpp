bool binarySearch(int* sortedData, int length, int target, int* result)
{
    if(sortedData == nullptr || length == 0)
    {
        *result = -1;
        return false;
    }
    
    int start = 0;
    int end = length-1;
    
    while(start <= end)
    {
        // int mid = (start + end) / 2;
        // "start + end" may cuase out of interger overflow.
        int mid = start + ( (end - start) / 2 );
        
        if(sortedData[mid] == target)
        {
            *result = mid;
            return true;
        }
        else if(target < sortedData[mid])
        {
            end = mid -1;
        }
        else if(sortedData[mid] < target)
        {
            start = mid + 1;
        }
    }
    
    *result = -1;
    return false;
}

bool binarySearchRecusive(int* sortedData, int start, int end, int target, int* result)
{
    if(start > end)
    {
        *result = -1;
        return false;
    }
 
    int mid = start + ( (end - start) / 2 );
    
    if(sortedData[mid] == target)
    {
        *result = mid;
        return true;
    }
    else if(target < sortedData[mid])
    {
        return binarySearchRecusive(sortedData, start, mid -1, target, result);
    }
    else //if(sortedData[mid] < target)
    {
        return binarySearchRecusive(sortedData, mid + 1, end, target, result);
    }
}

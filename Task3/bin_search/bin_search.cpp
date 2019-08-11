public int bsearch (int [],int n,int val)
{
	int low = 0;
	int high = n-1;
	while (low <= high)
	{
		int mid = (low+high)/2;
		if(a[mid] == value)
		{
			return mid;
		}
		else if (a[mid]<value)
		{
			low = mid -1;
		}
		else {
			high = mid -1;
		}
	}
	return -1;
}
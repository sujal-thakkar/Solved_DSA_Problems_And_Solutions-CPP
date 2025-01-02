int longestLen = 0;

        for(int i=0; i<n; i++) {
            int sum = 0;
            for(int j=i; j<n; j++) {
                sum += arr[j];
                if(sum == k) {
                    longestLen = max(longestLen, j - i + 1);
                    break;
                } else if(sum > k)
                    break;
            }
        }

        return longestLen;
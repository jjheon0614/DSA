for (int i = 0; i < n; i++) {
        if (i == 0) {
            sum += arr[i];
        } else {
            arr[i] += sum;
            sum += arr[i];
        }
    }
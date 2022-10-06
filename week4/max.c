// 5! = 5 * (4 * 3 * 2 * 1) = 5 * 4!
//
// base case
// 1! = 1
// 0! = 1
//
// recursive case 
// n! = n * (n - 1)!
//
// n = 10
// 10! = 10 * 9! = 10 * 9 * 8! = .... = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1! = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1
//
//
// sum_to_n
// sum_to_n(5) = 1 + 2 + 3 + 4 + 5
// sum_to_n(1) = 1
// sum_to_n(n) = n + sum_to_n(n - 1)

int sum_to_n(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return n + sum_to_n(n - 1);
}



// C function to find the largest element in an array, recursively.
// Returns the value of the largest element in the array.
// 
// array:  Array to search
// length: Number of elements in the array
int max(int array[], int length) {
    // 
    int first_element = array[0];
    if (length == 1) {
        // Handle the base-case of the recursion, at the end of the array.
        return first_element;
    } else {
        // Recurse on the rest of the array.
        // Finds the largest element after first_element in the array.
        int max_so_far = max(&array[1], length - 1);

        // Compare this element with the largest element after it in the array.
        if (first_element > max_so_far) {
            max_so_far = first_element;
        }
        return max_so_far;
    }
}

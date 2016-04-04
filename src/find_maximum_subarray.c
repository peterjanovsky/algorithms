#include <limits.h>

typedef struct {
    int max_left;
    int max_right;
    int sum;
} tuple;

/* finds the maximum subarray crossing the midpoint
 *
 * array array to inspect
 * low starting offset
 * mid middle offset
 * hight ending offset
 *
 * returns the tuple containing the indices demarcating a maximum subarray
 * crossing the midpoint
 */
tuple find_max_crossing_subarray(int array[], int low, int mid, int high)
{
    tuple tup;
    tup.max_left = 0;
    tup.max_right = 0;
    tup.sum = 0;

    int sum = 0;

    // assign left sum reserved value falling outside of possible array value
    int left_sum = INT_MIN;

    /*
     * find the maximum subarray of the left half
     *    assign accumulated sum of values at traversed offsets and index of
     *    current offset if the sum of the values in the traversed array
     *    positions is greater than the sum of the previous traversed values
     */
    for ( int i=mid; i >= low; i-- ) {
        sum += array[i];
        if ( sum > left_sum ) {
            left_sum = sum;
            tup.max_left = i;
        }
    }

    sum = 0;

    // assign right sum reserved value falling outside of possible array value
    int right_sum = INT_MIN;

    /*
     * find the maximum subarray of the right half
     *    assign accumulated sum of values at traversed offsets and index of
     *    current offset if the sum of the values in the traversed array
     *    positions is greater than the sum of the previous traversed values
     */
    for ( int j=mid+1; j < high; j++ ) {
        sum += array[j];
        if ( sum > right_sum ) {
            right_sum = sum;
            tup.max_right = j;
        }
    }

    // safety check, ensure calculation does not occur with reserved value
    if ( left_sum == INT_MIN ) left_sum = 0;
    if ( right_sum == INT_MIN ) right_sum = 0;

    tup.sum = left_sum + right_sum;

    return tup;
}

/* finds the maximum subarray
 *
 * array array to inspect
 * low starting offset
 * hight ending offset
 *
 * returns the tuple containing the indices demarcating a maximum subarray
 */
tuple find_max_subarray(int array[], int low, int high)
{
    // safety check
    if ( high == low ) {

        tuple tup;
        tup.max_left = low;
        tup.max_right = high;
        tup.sum = array[low];
        return tup;

    } else {

        /*
         * find the midpoint and it use to extract the
         *    maxium value of left, right and crossing subarrays
         *
         * essentially, this is achieved by recursively calling
         * find_max_subarray which splits the array in half with each call
         * until reaching offset 0 for low and high
         *    i.e.
         *      an array of size 6 the calls will generate the offsets
         *        find_max_subarray with 0 and 6
         *        find_max_subarray with 0 and 3
         *        find_max_subarray with 0 and 1
         *        find_max_subarray with 0 and 0
         */
        int mid = (low + high) / 2;
        tuple left = find_max_subarray(array, low, mid);
        tuple right = find_max_subarray(array, mid+1, high);
        tuple cross = find_max_crossing_subarray(array, low, mid, high);

        if (left.sum >= right.sum && left.sum >= cross.sum) return left;
        else if (right.sum >= left.sum && right.sum >= cross.sum) return right;
        else return cross;
    }
}

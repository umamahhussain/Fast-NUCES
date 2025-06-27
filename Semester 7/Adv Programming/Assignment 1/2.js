// Write a function rotateArray that rotates an array of integers in place to the right by k steps.
// For example, given the array [1,2,3,4,5,6,7] and k = 3, the output should be [5,6,7,1,2,3,4].
// Do this in O(1) space.

function rotate(arr,k){
    let i=0

    while(i<3){
        current=arr.pop()
        arr.unshift(current)
        i++
    }

    return arr
}

function reverseArray(arr, start, end) {
    while (start < end) {
        [arr[start], arr[end]] = [arr[end], arr[start]];
        start++;
        end--;
    }
}

function rotateArray(arr, k) {
    const n = arr.length;
    k = k % n; // if k is greater than the length of the array

    // reverse the entire array
    reverseArray(arr, 0, n - 1);

    // reverse the first k elements
    reverseArray(arr, 0, k - 1);

    // reverse remaining n - k elements
    reverseArray(arr, k, n - 1);
}


let array=[1,2,3,4,5,6,7]
let k=3

function1=rotate(array,k)
console.log("The result is: ",function1)

array=[1,2,3,4,5,6,7]
rotateArray(array, k);
console.log(array);
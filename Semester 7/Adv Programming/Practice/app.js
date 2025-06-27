const obj = { name: 'Alice', age: 25 };
for (let key in obj) {
  console.log(key, obj[key]); // name: 'Alice', age: 25
}
// const arr = [1, 2, 3, 4];
// const newArr = arr.slice(0, 2); // newArr = [2, 3]
// console.log(newArr)

const arr = [1, 67,89,4];
arr.splice(1, 1, 2, 3); 
console.log(arr)
let arr=[2,7,16,52,33,9,87,65,44,77]
arr=arr.reverse()
console.log(arr)

///////////////////////////////////////////

for(let i=0;i<arr.length;i++)
{
    if(arr[i]%2===0){
        arr[i]=arr[i]/2
    }
    else{
        arr[i]=arr[i]*3+1
    }
}

console.log(arr)

////////////////////////////////////////////

let filteredArr= arr.filter(element=> element<=100)
console.log("Filtered array: ",filteredArr)

///////////////////////////////////////////

let result= filteredArr.reduce((result,element)=>{
    return result+element
},0)
console.log("The total sum is: ",result)

///////////////////////////////////////////


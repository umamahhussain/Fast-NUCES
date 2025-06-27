function SplitArray(arr,...args){

    if(arr.length%2===0){
        firstHalf=arr.slice(0,arr.length/2)
        secondHalf=arr.slice(arr.length/2,arr.length)
    }
    else{
        firstHalf=arr.slice(0,Math.ceil(arr.length/2))
        secondHalf=arr.slice(arr.length/2+1,arr.length)
    }

    console.log("First Half of Array: ",firstHalf)
    console.log("Second Half of Array: ",secondHalf)

    /////////////////////////////////////////////////

    let newArr= firstHalf.concat(args)
    console.log("After Concat: ",newArr)

    ////////////////////////////////////////////////

    let total1= newArr.reduce((sum,element)=>{
        return sum+element
    },0)
    console.log("Sum of First Half: ",total1)

    let total2= secondHalf.reduce((sum,element)=>{
        return sum+element
    },0)
    console.log("Sum of Second Half: ",total2)

    ///////////////////////////////////////////////

    let result=total1*total2
    return result

}



let arr = [1, 2, 3, 4, 5, 6]
let ans= SplitArray(arr,20,10,30)
console.log("Final Answer: ",ans)


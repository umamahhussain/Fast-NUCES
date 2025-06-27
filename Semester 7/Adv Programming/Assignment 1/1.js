// Write a function flattenArray that takes a deeply nested array of integers and returns a
// flattened array. For example, given the input [[1, [2, [3]]], 4, [5, [6, [7]]]], the output should
// be [1, 2, 3, 4, 5, 6, 7]. Implement the function without using Array.prototype.flat()

function flattenArray(arr){
result=[];
stack=[...arr]

while(stack.length!=0){
    current=stack.pop()

    if(typeof(current)==="object"){
        stack.push(...current)
    }
    else{
        result.push(current)
    }
}

return result.reverse()

}


function flattenArray2(arr){
    
    temp=JSON.stringify(arr)
    result=[]

   for( let i=0; i<temp.length; i++ ) {
        current=temp[i]

        if(current==='['||current===']'||current===','){
            continue
        }
        else{
            result.push(Number(current))
        }
    }
    
    return result
    
    }


let arr= [[1, [2, [3]]], 4, [5, [6, [7]]]]
result= flattenArray(arr);
console.log("The flattened array from the first function is: ",result)

result2= flattenArray2(arr);
console.log("The flattened array from the second function is: ",result2)
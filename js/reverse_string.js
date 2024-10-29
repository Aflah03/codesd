function reverse(str){
    let reversed=""

    // for(let i=0;i<str.length;i++){
    //     reversed = str[i]+ reversed;
    // }
    for(let char of str){
        reversed = char+ reversed;
    }
    return reversed
}

function str_to_array(str){
    const  strToArray = str.split('');//this sentence itself does that
    return strToArray;
}

console.log(reverse("Coding money"))
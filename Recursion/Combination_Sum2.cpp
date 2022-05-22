// Brute force- same as combination_sum1 ,
// only difference will be in calling of left recursion change the index
// to index+1 bcz we cannot take same elements here 
// and put the combinations into set so that we should not have any
// duplicate combination
// TC:O(2^n *k)


// optimal approach--this time we are going to try to pick subsequences instead 
// pick and non-pick approach.

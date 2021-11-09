class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result=new ArrayList<>();
        List<Integer> temp=new ArrayList<>();
        Set<Integer> set =new HashSet<>();
        if(nums==null||nums.length==0){
            return result;
        }
        dfs(nums,result,temp,set,nums.length);
        return result;
    }
    
    public void dfs(int[] nums,List<List<Integer>> result,List<Integer> temp,Set<Integer> set,int k){
        if(k==0){
            result.add(new ArrayList<Integer>(temp));
            return;
        }
        for(int i=0;i<nums.length;++i){
            if(!set.contains(i)){
                temp.add(nums[i]);
                set.add(i);
                dfs(nums,result,temp,set,k-1);
                set.remove(i);
                temp.remove(temp.size()-1);
            }
        }
    }
}

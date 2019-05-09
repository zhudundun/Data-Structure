
vector<string> NoProblem(int start, vector<int> created, vector<int> needed) {

    // your code here
int total=start;
vector<string> answer;

if(needed[0]>total)answer.push_back("No problem. :(");
else
{
  answer.push_back("No problem! :D");
  total-=needed[0];
}
//std::cout<<total<<std::endl;
total+=created[0];

for (int i=1;i<12;i++){
if(needed[i]>total){
  answer.push_back("No problem. :(");

}
else{
  total-=needed[i];
  answer.push_back("No problem! :D");
}
//std::cout<<total<<std::endl;

total+=created[i];


}
return answer;
}

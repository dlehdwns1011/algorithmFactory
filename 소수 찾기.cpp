using namespace std;
// 효율성
int solution(int n) {
    int answer = 0;
     
    bool check[1000000] = {false,};

    for(int i = 2 ; i <= n ; ++i)
    {
        if(check[i] == false)
                ++answer;   
        
        for(int j = 2 ; i * j <= n ; ++j)
            check[i*j] = true;
    }
        
    return answer;
}

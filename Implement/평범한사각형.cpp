using namespace std;

int gcd(int w, int h) {
    if (w % h == 0) {
        return h;
    } else {
        return gcd(h, w % h);
    }
}

long long solution(int w,int h) {
    long long answer = 1;
    
    answer = (long long)w * (long long)h - (w + h);
    answer += gcd(w, h);
    
    return answer;
}
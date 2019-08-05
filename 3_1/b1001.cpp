
void b1001(int &step, int n){
    if (n % 2 == 0){
        n = n / 2;
    } 
    else {
        n = (3 * n +1 ) / 2;
    }

    step = step + 1;

    if (n == 1) {
        return;
    }
    else {
        b1001(step, n);
    }
}
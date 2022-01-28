int funcao_param(int a, int b){
    int c;
    c = a + b;
    return c;
}

int main(){
    int a;
    a = 10;
    if(a > 20){
        int b;
        b = a * 2;
    }
    b = 2;

    int c;
    int d;
    d = 10;
    c = funcao_nao_declarada(d);

    int e;
    int f;
    e = 5;
    f = 15;

    int g;
    g = funcao_param(e);

    float h;
    h = 15.5;
    int i;
    i = 5;
    int j;
    j = h - i;
    return 0;
}
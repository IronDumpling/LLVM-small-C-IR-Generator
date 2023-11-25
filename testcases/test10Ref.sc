// Testing for function parameters
void abc(int a[], bool b[]){
    
}

void def(int a, bool b){
    
}

int main(int a, bool b, int c[], bool d, bool e[]){
    int z[2];
    bool y[3];
    a = 1;
    b = true;
    z[666] = 1;
    y[777] = true;
    c[100] = 2;
    a = c[666];
    abc(z, e);
    abc(c, y);
    def(z[a/2+5], e[a*3]);
    def(z[c[z[c[z[b]]]]] * c[z[c[z[a]]]], e[a*3] && e[z[c[2]]]);

    if(a > z[c[z[a]]]){
        return z[c[z[a]]];
    }
    else{

    }
    a = z[c[z[a]]];
    return a;
}

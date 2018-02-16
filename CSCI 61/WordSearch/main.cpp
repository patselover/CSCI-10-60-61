#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;
size_t N = size_t();
size_t M = size_t();
void searchforwards(char **a,size_t N,size_t M,std::unordered_map<string,int> &dict);
void searchbackwards(char **a,size_t N,size_t M,std::unordered_map<string,int> &dict);
void searchtopdown(char **a,size_t N,size_t M,std::unordered_map<string,int> &dict);
void seachbottomup(char **a,size_t N,size_t M,std::unordered_map<string,int> &dict);
void searchdiagforward(char **a,size_t N,size_t M,std::unordered_map<string,int> &dict);
void searchdiagbackward(char **a,size_t N,size_t M,std::unordered_map<string,int> &dict);
void wordsearch(char ** a, int N, int M,std::unordered_map<string,int> &dict);


int main()
{
    ifstream is;
    is.open("/Users/PatSelover/Desktop/puzzle.txt");
    if (is.fail())
        {
            cout << "Can't open puzzle!" << endl;
            exit(1);
        }

        string line;

        while (getline(is, line)){
            ++M;
            N = line.size()/2;
        }
        is.close();
        is.open("/Users/PatSelover/Desktop/puzzle.txt");
        char** data;
        data = new char*[N];//allocate rowsize many pointers to chars as the rows. note char* in new.
        for(size_t i = 0; i < N; i++)
            data[i] = new char[M];  //allocate the collumns at each row.
        line = "";
        size_t i = 0;
        while(getline(is, line))
        {
            stringstream ss(line);
            vector<char> row;
            size_t j = 0;
            char c;
            while(ss>>c){
                for(j = 0; j<M; ++j){
                    data[i][j]=c;
                    ss>>c;
                }
                ++i;
            }
        }

        ifstream ds("/Users/PatSelover/Desktop/dict.txt");
        if (ds.fail())
        {
            std::cout << "Can't open dictionary!" << std::endl;
            exit(1);
        }

        string word;
        std::unordered_map<string, int> dict;
        while (ds >> word)
            dict[word] = 1;

    wordsearch(data, N, M, dict);

    return 0;
}
void print(string word, int horiz, int vert,int x, int y){
    cout<<word<<" found at ("<< horiz<<", "<< vert<<")"<< " to "<< "("<< x<<", "<< y<<")"<<endl;
}
void searchforwards(char ** a, int N, int M,std::unordered_map<string,int> &dict){
    for(int i = 0; i<N; ++i){
        for(int j = 0; j<M; ++j){
            string temp = "";
            for(int k = j; k<M && k<N; ++k){
                temp += a[i][k];
                if(dict[temp] == 1 && temp.length() > 5){
                    print(temp,i,j,i-temp.length()+1,j);
                }
            }
        }
    }
}
void searchbackwards(char ** a, int N, int M,std::unordered_map<string,int> &dict){
    for(int i = 0; i<N; ++i){
        for(int j = M-1; j>0; --j){
            string temp = "";
            for(int k = j; k>-1 && k>-1; --k){
                temp = temp + a[i][k];
                if(dict[temp] == 1 && temp.length() > 5){
                    print(temp,i,j,i+temp.length()-1,j);
                }
            }
        }
    }
}
void searchtopdown(char ** a, int N, int M,std::unordered_map<string,int> &dict){
    for(int j = 0; j<N; ++j){
        for(int i = 0; i < M; ++i){
            string temp = "";
            for(int k = j; k<M && k<N; ++k){
                temp += a[k][i];
                if(dict[temp] == 1 && temp.length() > 5){
                    print(temp,i,j,i,j-temp.length()+1);
                }
            }
        }
    }
}
void seachbottomup(char ** a, int N, int M,std::unordered_map<string,int> &dict){
    for(int i = 0; i<N; ++i){
        for(int j = M-1; j > -1; --j){
            string temp = "";
            for(int k = j; k>-1 && k>-1; --k){
                temp = temp + a[k][i];
                if(dict[temp] == 1 && temp.length() > 5){
                    print(temp,i,j,i,j+temp.length()-1);
                }
            }
        }
    }
}
void searchdiagforward(char ** a, int N, int M,std::unordered_map<string,int> &dict){
    for(int i = 0; i<N; ++i){
        for(int j = M-1; j > -(M+1); --j){
            string temp = "";
            for(int k = 0; k<N && k < M && (j+k)<M && (i+k)<N; ++k){
                temp += a[i+k][j+k];
                if(dict[temp] == 1 && temp.length() > 5){
                    print(temp,i,j,i+temp.length()-1,j+temp.length()-1);
                }
            }
        }
    }
    for(int j = 0; j<M; ++j){
        for(int i = 0; i < N; ++i){
            string temp = "";
            for(int k = 0; k<N && k < M && (i-k)>-1; ++k){
                temp += a[i-k][j+k];
                if(dict[temp] == 1 && temp.length() > 5){
                    print(temp,i,j,i-temp.length()+1,j+temp.length()-1);
                }
            }
        }
    }
}
void searchdiagbackward(char ** a, int N, int M,std::unordered_map<string,int> &dict){
    for(int j = M-1; j > -(M+1); --j){
        for(int i = 0; i < N; ++i){
            string temp = "";
            for(int k = 0; k <N && k < M && (j-k)>-1 && (i-k)>-1; ++k){
                temp = temp + a[i-k][j-k];
                if(dict[temp] == 1 && temp.length() > 5){
                    print(temp,i,j,i-temp.length()+1,j-temp.length()+1);
                }
            }
        }
    }
    for(int i = 0; i<N; ++i){
        for(int j = 0; j<M; ++j){
            string temp = "";
            for(int k = 0; k <N && k < M && (j-k)>-1 && (k+i)<N; ++k){
                int d = 0;
                while((d+k+ ) > -1){
                temp = temp + a[i+k][j-k];
                if(dict[temp] == 1 && temp.length() > 5){
                    print(temp,i,j,i+temp.length()+1,j-temp.length()+1);
                }
                }
            }
        }
    }
}


void wordsearch(char ** a, int N, int M,std::unordered_map<string,int> &dict){
    searchforwards(a,N,M,dict);
    searchbackwards(a,N,M,dict);
    searchtopdown(a,N,M,dict);
    seachbottomup(a,N,M,dict);
    searchdiagforward(a,N,M,dict);
    searchdiagbackward(a,N,M,dict);
}


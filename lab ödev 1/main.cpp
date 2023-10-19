//github denemeeeeee
#include <iostream>
#include <fstream>

using namespace std;
int const ROWS = 10, COLUMNS = 20;

//int const maxPixels = ROWS*COLUMNS;//max piksel sayısı


void blobsCenterOfMass(char array[][COLUMNS], int centerOfMass[]){
    //int pixel = 0;
    int totalX = 0;
    int totalY = 0;
    

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (array[i][j] == 'x' && array[i+1][j] == 'x' || array[i][j+1] == 'x' || array[i-1][j] == 'x' || array[i][j-1] == 'x')
            {
                //int coordinates[2][maxPixels]; burada 1den fazla blobu tutmaya çalışmıştım amaanlamsız oldu 
                //coordinates[0][pixel]=i;
                //coordinates[1][pixel]=j;
                totalX += j;
                totalY += i;
                //pixel++;                
            }  
        } 
    }
    centerOfMass[0] = totalX/2;
    centerOfMass[1] = totalY/2;
}

int main() {
	fstream my_file;
	my_file.open("blobs.txt", ios::in);
    int centerOfMass[2]={};
    
	if (!my_file) {
		cout << "No such file";
	}
	else {    
        char file[ROWS][COLUMNS];
	
        for(int i=0; i<COLUMNS;i++){
            for (int j = 0; j < COLUMNS; j++)
            {
                char ch;
                if (my_file.get(ch)) {
                    if (ch == '\n')
                    {
                        j=20;// to skip to the next i 
                        continue;
                    }
                file[i][j] = ch;
                }   

                //cout << i << " " << j << " "; bu kısmı nasıl dosyaokuduğunu görmek için yazmıştım işlevsiz 
                //cout << file[i][j] << "\n";

                if (my_file.eof())
                    break;
            }  
        }
        blobsCenterOfMass(file, centerOfMass);
        cout << "center of the mass is "<< centerOfMass[0] << "," << centerOfMass[1];
        
	}
    
	
    my_file.close();

    


	return 0;
}


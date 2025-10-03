#include  <stdio.h>
#include <math.h>
#include <stdlib.h> 

float chill(float temp, float wind);

int main(int argc, char *argv[])
{
    const char* headers[] = {"Temp", "Wind", "Chill"};
        //No arguments
        if (argc == 1) {

                float values[18][3];
                //Populate the array
                float start_temp = -10.0;
                int count = 0;
                for (int i = 0; i < 6; i++) {
                    float start_wind = 5.0;
                    for (int j = 0; j < 3; j++) {
                        values[count][0] = start_temp;
                        values[count][1] = start_wind;
                        values[count][2] = chill(start_temp, start_wind);
                        start_wind += 5.0;
                        count +=1;
                    }
                     start_temp += 10.0;
                 }
                 //Print everything
                 for (int i = 0; i < 3; i++) {
                    printf("%s\t", headers[i]);
                }
                 printf("\n");

                 for (int i = 0; i < 3; i++) {
                    printf("---- \t");
                }
                printf("\n");
                 
                 for (int i = 0; i < count; i++) {
                     for (int j = 0; j < 3; j++) {
                         printf("%.1f\t", values[i][j]);
                     }
                     printf("\n");
                 }
        }
        //One argument
        else if (argc == 2) {
            double temperature = atof(argv[1]);

            //Check if acceptable
            if (temperature < 50 && temperature > -99) {
                float values[3][3];
                float start_wind = 5.0;
                for (int i = 0; i < 3; i++) {
                    values[i][0] = temperature;
                    values[i][1] = start_wind;
                    values[i][2] = chill(temperature, start_wind);
                    start_wind += 5.0; 
                }
                //Print everything
                for (int i = 0; i < 3; i++) {
                    printf("%s\t", headers[i]);
                }
                 printf("\n");

                 for (int i = 0; i < 3; i++) {
                    printf("---- \t");
                }
                printf("\n");
                 
                 for (int i = 0; i < 3; i++) {
                     for (int j = 0; j < 3; j++) {
                         printf("%.1f\t", values[i][j]);
                     }
                     printf("\n");
                 }
            }


            else {
                printf("Temperature %f must be between -99 and 50\n", temperature);
                return -1;
            }
        }
        //Two arguments
        else if (argc == 3) {
            //Temp check
            double temperature = atof(argv[1]);
            double speed = atof(argv[2]);
            double res = chill(temperature, speed);

            if (temperature > 50 || temperature < -99) {
                printf("Temperature %f should be between -99 and 50\n", temperature);
                return -1;
            }
            if (speed < 0.5) {
                printf("Wind speed %f should be >= 0.5\n", speed);
                return -1;
            }
            for (int i = 0; i < 3; i++) {
                printf("%s\t", headers[i]);
            }
             printf("\n");

             for (int i = 0; i < 3; i++) {
                printf("---- \t");
            }
            printf("\n");

            printf("%.1f \t", temperature);
            printf("%.1f \t", speed);
            printf("%.1f \t \n", res);


        }
    return 0;
    }

float chill(float temp, float wind) 
{
    float value = 35.74 + 0.6215*temp - 35.75*pow(wind, 0.16) + 0.4275*temp*pow(wind, 0.16);
    return value;
}



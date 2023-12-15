#include<stdio.h>   
#include<stdlib.h>   // Λόγω χρήσης της strtoull //

 unsigned long long sequence_length( unsigned long long temp){    //τυπου unsigned long long για μεγαλύτερους αριθμούς- παίρνει το τεμπ ως ο εκάστοτε αριθμός στο εύρος που δώσαμε//
  
    int g = 0;        // μετράει το μήκος κολατζ η μεταβλητή g //

    while (temp != 1){           // συνθήκη για να τελειώνει όταν φτάσει στο 1//

        if ( temp % 2 ==0){             
            temp = temp / 2;
        }else{
            temp = temp * 3 +1;
        }                                                           
     g++;        // αυξάνει για καθε τροποποίηση του εκαστοτε αριθμού//
    }

    return g + 1;   // επιστρέφει το μήκοσ ( +1 γιατι εντός του μηκους συμπεριλαμβάνεται και ο ιδιος ο αριθμός //
 }   
   
int main ( int argc, char *argv[]){


    if ( argc != 3){
        printf("Give me two numbers\n");

        return -1;
    }
  unsigned long long m = strtoull(argv[1], NULL, 10); //  κανει convert σε unsigned long long //
  unsigned long long n = strtoull(argv[2], NULL, 10);  // το ιδιο και με το n //
  unsigned long long temp, j;  /*δήλωση μεταβλητών*/
  unsigned long long max = 0;
  unsigned long long length = 0;                
  
   
   if (( n <= 0 || m <= 0) || (n > 100000000 || m > 100000000)){   // έλεγχος εγκυρότητας για τις τιμες ( αν ειναι αρνητικές ή μεγαλύτερες του 100.000.000)
        printf("%d\n", 0);  // εμφανίζει 0 απο την εκφώνηση//
        return -1;

   }else if(n > m){   
        for( j = m; j <= n; j++){         // loop για ολο το εύρος των αριθμών που ορίσαμε//
            temp = j;         // ανάθεση τιμης σε άλλη μεταβλητή για να αποφύγουμε τροποποιήσεις του j//
            length = sequence_length(temp);      // length παίρνει την τιμή του g από την sequence length//
              if (length >= max){     // εύρεση  max εντός βρογχου //
                   max = length;
    }  

        }
   }else if( m >= n){      
    for ( j = n; j<=m; j++){   // η ιδια διαδικασια αλλα εκτελείτε οταν το m>n και οταν δώσουμε 2 ιδιους αριθμούς//
        int temp = j;
        length = sequence_length(temp);
            if (length >= max){
               max = length;
    }

    }
   }
   printf("%llu\n", max ); //τύπωμα μαξ (μεγιστο μήκος ακολουθίας κολατζ) //
    
   return 0;

}

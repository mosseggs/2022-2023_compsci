if (plain[num] >= 'a' && plain[num] <= 'z')
        {
            // converts the Lowercase (as ascii) into lowercase (as numbers)
            convert = plain[num] - 97;
            // print
            printf("%c", ((convert + key[cipher]) % 26) + 97);
        }
        // uppercase
        else if (plain[num] >= 'A' && plain[num] <= 'Z')
        {
            // converts the uppercase (as ascii) into uppercase (as numbers)
            convert = plain[num] - 65;
            // print
            printf("%c", ((convert + key[cipher]) % 26) + 65);
        }
        else
        {
            printf("%c", plain[num]);
        }
        cipher=0;
    }
    printf("\n");
    return 0;
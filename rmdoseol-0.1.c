/* rmdoseol.c
 *
 *  This program finds the ^M eol character and deletes it.  IF I understood Git better I probabably would never
 *   have written it.  BTW .gitattributes is what you want to edit.
 *   This version accepts one file at a time and replaces it.
 *   THEREFORE make sure you are only doing this operation on real text files.
 *   So perhaps writing a script the determines whether the bunch of files you want to do this action on include:
 *     $ "file blahblah.c | grep text"
 *        would be prudent indeed.
 *  author: Peter Suchsland
 *   compile like so:
 *    $ gcc -o rmdoseol.exe rmdoseol-0.1.c
 */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]) {
    FILE    *in_file_ptr;
    FILE    *out_file_ptr;
    char    infilename[512];
    char    outfilename[512];
    char    ch = '\0';

    if (argc == 2 ) {
        strcpy(infilename, argv[1]);
        infilename[strlen(infilename)] = '\0'; // remove end garbage
        strcpy(outfilename, "temp.rmdoseol");
    }

    if (argc != 2) {  //  Usage
        fprintf(stderr,"USAGE: rmdoseol.exe file-with-crlfs\n");
        exit(1);
    }

    in_file_ptr = fopen(infilename, "rb");
    out_file_ptr = fopen(outfilename,"wb+");

    if (in_file_ptr == NULL) {
        fprintf(stderr, "Problem finding file: %s\n", infilename);
        exit(2);
    }

    //  Check each character and replace offending eol with nothing.
    while(1) {
        ch = fgetc(in_file_ptr);
        if (ch == EOF)
            break;
        if (ch == '\015') {
            fputs("", out_file_ptr);
        } else {
            fputc(ch, out_file_ptr);
        }
    }

    fclose(in_file_ptr);
    fclose(out_file_ptr);

    //  Copy back to original file
    if (argc == 2 ) {
        in_file_ptr = fopen(outfilename, "rb");
        out_file_ptr = fopen(infilename,"wb+");
        while(1) {
            ch = fgetc(in_file_ptr);
            if (ch == EOF)
                break;
            else {
                fputc(ch, out_file_ptr);
            }
        }
        fclose(in_file_ptr);
        fclose(out_file_ptr);
        remove(outfilename);
    }
    return(0);
}

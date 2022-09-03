    #include<iostream>

    #include<vector>

    #include<stdlib.h>

    using namespace std;

    void to_upper_case(vector<char>& text, int len)

    {

        for (int j = 0; j < len; j++)

        {

            if (text[j] >= 97 && text[j] <= 122)

                text[j] -= 32;

        }

    }

    void print_string(vector<char> text, int len)

    {

        for (int j = 0; j < len; j++)

        {

            cout << (char) (text[j] + 65);

        }

        cout << endl;

        return;

    }

    size_t get_input(vector<char>& msg)

    {

        char a;

        while (1)

        {

            a = getchar();

            if (a == '\n')

                break;

            msg.push_back(a);

        }

        return msg.size();

    }

    int main()

    {

        vector<char> msg;

        vector<char> enc_msg;

        vector<char> dec_msg;

        int *p;

        int j;

        size_t len;

        cout << "Enter Message to Encrypt:";

        len = get_input(msg);

        to_upper_case(msg, len);

        p = (int*) malloc(msg.size() * sizeof(int));

        for (j = 0; j < len; j++)

        {

            p[j] = rand() % 26;

            if (msg[j] >= 65 && msg[j] <= 90)

                enc_msg.push_back((char) ((msg[j] - 65 + p[j]) % 26));

            else if (msg[j] >= 97 && msg[j] <= 122)

                enc_msg.push_back((char) ((msg[j] - 97 + p[j]) % 26));

            else

                enc_msg.push_back((char) msg[j]);

        }

        cout << "\nEncoded Message:";

        print_string(enc_msg, len);

        cout << "\nKey for decryption:\n";

        for (j = 0; j < len; j++)

        {

            cout << (char) (p[j] + 65);

        }

        cout << endl;

        cout << "\nDecrypted Message:";

        for (j = 0; j < len; j++)

        {

            if ((enc_msg[j] - p[j]) < 0)

                dec_msg.push_back((char) (enc_msg[j] - p[j] + 26));

            else if ((enc_msg[j] - p[j]) >= 0)

                dec_msg.push_back((char) (enc_msg[j] - p[j]));

            else

                dec_msg.push_back((char) enc_msg[j]);

        }

        print_string(dec_msg, len);

        return 0;

    }

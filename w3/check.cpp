using namespace w3;
int main() {
    Text r("gutenberg_shakespeare.txt");
    r.display();
    Text d = r;
    cout << "hbsdbchsbjsnijnjndfhbsjnbhdhcbhb\n\n\n\n\n\n" << endl;
    d.display();
    Text c = move(r);
    r.display();
    c.display();

}


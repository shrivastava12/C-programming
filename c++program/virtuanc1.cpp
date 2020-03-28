  #include<iostream>
  #include<cstring>
  using namespace std;

  class media
  {
  protected:
    char title[50];
    float price;
  public:
    media(char *s,float a)
    {
        strcpy(title,s);
        price = a;
    }
    virtual void display(){}
  };
  class book : public media
  {
      int pages;
  public:
    book(char *s,float a,int p):media(s,a)
    {
        pages = p;
    }
    void display();
  };
  class tape :public media
  {
      float time;
  public:
    tape(char *s,float a,float t):media(s,a)
    {
        time = t;
    }
    void display();
  };
  void book :: display()
  {
      cout<<"\n Title: "<<title;
      cout<<"\n pages: "<<pages;
      cout<<"\n Price: "<<price;
  }
  void tape::display()
  {
      cout<<"\n Title: "<<title;
      cout<<"\n time: "<<time;
      cout<<"\n price: "<<price;
  }
  int main()
  {
        char * title = new char[30];
        float price,time;
        int pages;

        //Book details
        cout<<"\nEnter the book details\n";
        cout<<" Title: ";cin>>title;
        cout<<" Price: ";cin>>price;
        cout<<" Pages: ";cin>>pages;

        book book1(title,price,pages);

        //Tape details
        cout<<"\n Enter the tape details \n";
        cout<<" Title: ";cin>>title;
        cout<<" Price: ";cin>>price;
        cout<<" play time: ";cin>>time;
        tape tape1(title,price,time);

        media* List[2];
        List[0] = &book1;
        List[1] = &tape1;

        cout<<"media details:";
        cout<<"\n.......Book.......";
        List[0] -> display(); //display book detail;
        cout<<"\n .......Tape......";
        List[1] -> display(); //Tape display

        return 0;

  }

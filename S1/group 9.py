import pickle
import os

all_id=[]

def clear():
    os.system('cls')


class student():
    sub=['MA','ICS','BEE','EM','PH','SE']
    s=['Series 1','Series 2','Assignment','Aptitude']
    k=0
    def __init__(self):
        self.s1marks=[]
        self.s2marks=[]
        self.asmarks=[]
        self.apmarks=[]
        self.total=[]
        self.total1=0
        self.eid=0
        self.name='null'
        
    

    def getdata(self):
        self.eid=input("Enter Id: ")
        while self.eid in all_id:
            self.eid=input("Already Exist, Enter Id: ")
        self.name=raw_input("Enter Name: ")
        print "-----Subjects-----"
        print "MA: Calcalus"
        print "ICS: Introduction to Computer Science"
        print "BEE: Basic Electrical Engg."
        print "EM: Engg. mechanics"
        print "PH: Engg. physics"
        print "SE: Introduction to Sustainable engg."
        print "------------------"
        self.getmark()
        self.calculate()


    def getdata1(s):
        print "-------Type-------"
        print "1: Series 1"
        print "2: Series 2"
        print "3: Assignment"
        print "4: Aptitude"
        print "------------------"
        a=input("Enter type:")-1
        print "-----------------Subjects-----------------"
        print "1: MA: Calcalus"
        print "2: ICS: Introduction to Computer Science"
        print "3: BEE: Basic Electrical Engg."
        print "4: EM: Engg. mechanics"
        print "5: PH: Engg. physics"
        print "6: SE: Introduction to Sustainable engg."
        print "------------------------------------------"
        b=input("Enter Sub:")-1
        if a==0:
            s.s1marks[b]=check1(input("Enter Mark"))
        if a==1:
            s.s2marks[b]=check1(input("Enter Mark"))
        if a==2:
            s.asmarks[b]=check2(input("Enter Mark"))
        if a==3:
            s.apmarks[b]=check2(input("Enter Mark"))
        s.calculate()
            

    def calculate(self):
        print "lol"
        self.total=[]
        for i in range(0,len(self.sub)):
            a=self.s1marks[i]+self.s2marks[i]+self.asmarks[i]+self.apmarks[i]
            self.total.append(a)
        self.total1=0
        for i in self.total:
            self.total1+=i
            

    def getmark(self):
        self.s1marks=[]
        self.s2marks=[]
        self.asmarks=[]
        self.apmarks=[]
        self.total=[]
        for j in self.s:
            for i in self.sub:
                print '%30s'%("Enter "+i+" mark for "+j+" : "),
                if j=="Series 1" or j=="Series 2":
                    a=check1(input())
                else:
                    a=check2(input())
                if j=="Series 1":
                    self.s1marks.append(a)
                    
                elif j=="Series 2":
                    self.s2marks.append(a)

                elif j=="Assignment":
                    self.asmarks.append(a)

                else:
                    self.apmarks.append(a)
                
            
    
            

    def outdata1(self):
        student.k+=1
        print student.k,"ID:",self.eid, "|","Name:",self.name
        print"--------------------------------------------------------------------------------------------------------------"
        


    def outdata(self):
        print"--------------------------------------------------------------------------------------------------------------"
        print "ID:",self.eid
        print "Name:",self.name
        self.outmarks()



    def outmarks(self):
        #print self.sub,self.s1marks,self.s2marks,self.total
        print"--------------------------------------------------------------------------------------------------------------"
        print"| Subject    |   %s   |    %s    | %s     | %s      | Total        | %s    "%(self.s[0],self.s[1],self.s[2],self.s[3],"Status")
        print"--------------------------------------------------------------------------------------------------------------"
    
        for i in range(0,len(self.sub)):
            if self.total[i]>=22.5:
                p="PASS"
            else:
                p="FAIL"
            #print self.total1
            #print "%3s          |  %4.2f        |  %3.2f          |  %3.2f          |        %3.2f   |        %3.2f  " % (self.sub[i],self.s1marks[i],self.s2marks[i],self.asmarks[i],
            #                                                                              self.apmarks[i],self.total[i])
            print "%3s          |  %4s        |  %4s          |  %4s          |        %4s   |        %4s  |        %4s   " % (self.sub[i],str(float(self.s1marks[i])),str(float(self.s2marks[i])),str(float(self.asmarks[i])),
                                                                                          str(float(self.apmarks[i])),str(float(self.total[i])),p)
        print"--------------------------------------------------------------------------------------------------------------"       
        
            
                
  
def check1(a):
    while a>20 or a<0:
        a=input("Enter a mark between 0 and 20 :")
    return a

  
def check2(a):
    while a>5 or a<0:
        a=input("Enter a mark between 0 and 5 :")
    return a                
        

def einput():
    get_all_id()
    f=open('student.dat','ab')
    e=student()
    e.getdata()
    pickle.dump(e,f)
    f.close()


def edisplay():
    f=open('student.dat','rb')
    try:
        while True:
            e=pickle.load(f)
            e.outdata()
    except EOFError:
        pass
    f.close()


def edisplay1():
    print"--------------------------------------------------------------------------------------------------------------"
    f=open('student.dat','rb')
    try:
        while True:
            e=pickle.load(f)
            e.outdata1()

    except EOFError:
        pass
    student.k=0
    f.close()


def esearch(r=0):
    if r==0:
        edisplay1()
    f=open('student.dat','rb')
    if r==0:
        r=input('Enter student ID: ')
    try:
        while True:
            e=pickle.load(f)
            if e.eid==r:
                print "student Found!"
                e.outdata()
                break
    except EOFError:
        print "student not found!!"
    f.close()


def high_mark():
    h=0;hid=0
    f=open('student.dat','rb')
    try:
        while True:
            e=pickle.load(f)
            if e.total1>h:
                h=e.total1
                hid=e.eid
                #print h,hid
    except EOFError:
        pass
    f.close()
    esearch(hid)


def edelete():
    edisplay1()
    f=open('student.dat','rb')
    f1=open('temp.dat','wb')
    flag=0
    id=input('Enter student ID: ')
    
    try:
        while True:
            e=pickle.load(f)
            if e.eid!=id:
                pickle.dump(e,f1)
            else:
                flag=1
    except EOFError:
        pass
    f.close();f1.close()
    os.remove('student.dat');os.rename('temp.dat','student.dat')
    if flag==1:
        print "Details Deleted!"
    else:
        print "Id not found!"


def eupdate():
    get_all_id()
    flag=0
    edisplay1()
    f=open('student.dat','rb')
    f1=open('temp.dat','wb')
    id=input('Enter student ID: ')
    clear()
    try:
        while True:
            e=pickle.load(f)
            if e.eid==id:
                e.getdata()
                pickle.dump(e,f1)
                print "Updated!"
                flag=1
            else:
                pickle.dump(e,f1)
    except EOFError:
        pass
    if flag!=1:
        print "Student not found!"
    f.close();f1.close()
    os.remove('student.dat');os.rename('temp.dat','student.dat')



def eupdate1():
    get_all_id()
    flag=0
    
    f=open('student.dat','rb')
    f1=open('temp.dat','wb')
    edisplay1()
    id=input('Enter student ID: ')
    clear()
    try:
        while True:
            e=pickle.load(f)
            if e.eid==id:
                e.outdata()
                e.getdata1()
                pickle.dump(e,f1)
                print "Updated!"
                e.outdata()
                flag=1
            else:
                pickle.dump(e,f1)
    except EOFError:
        pass
    if flag!=1:
        print "Student not found!"
    f.close();f1.close()
    os.remove('student.dat');os.rename('temp.dat','student.dat')



def get_all_id():
    global all_id
    f=open('student.dat','rb')
    try:
        while True:
            
            e=pickle.load(f)
            all_id.append(e.eid)
            
            
    except EOFError:
        pass
    f.close()



get_all_id()
uid=""
pas=""
loop='y'
while loop=='y':
    if (uid=="" and pas==""):
        clear()
        print "-----Login-----"
        uid=raw_input("Username :")
        pas=raw_input("Password :")
        print "--------------"
    if (uid=="admin" and pas=="admin")or(uid=="allen" and pas=="allen")or(uid=="amit" and pas=="amit"):
        clear()
        print "-----Menu-----"
        print "1: Input"
        print "2: Update"
        print "3: Delete"
        print "4: Display"
        print "5: Search"
        print "6: Highest Mark"
        print "--------------"
        n=input("Enter Choice: ")
        if n==1:
            einput()
        elif n==2:
            print "-----Update-----"
            print "1: Full Editing"
            print "2: Single Editing"
            print "--------------"
            w=input("Enter Choice :")
            while (w>2 or w<=0):
                w=input("Invalid, Enter again :")
            if w==1:
                eupdate()
            elif w==2:
                eupdate1()
        elif n==3:
            edelete()
        elif n==4:
            edisplay()
        elif n==5:
            esearch()
        elif n==6:
            high_mark()
        else:
            print "Choice not found!"

    else:
        print "Username or Password is incorrect!"
        uid=""
        pas=""
    loop=raw_input("Do you want to continue? y/n: ")
    
    while True:
        if loop=="y" or loop=="n":
            break
        else:
            loop=raw_input("Invaid Input, Do you Continue? y/n: ")

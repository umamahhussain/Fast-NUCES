class Student:
    def __init__(self, matrix):
        self.matrix = matrix

    def DisplayMatrix(self):
        print("Name:        Roll Num:             Subject:          Marks:         Grade:       \n")
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[i])):
                print(self.matrix[i][j], "            ", end="")
            print("\n")
    
    def CalcGrade(self):
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[i])):
                if self.matrix[i][3] is not None:  # Ensure the value is not None
                    if(self.matrix[i][3]<100 and self.matrix[i][3]>=90):
                        self.matrix[i][4]="A+"
                    if(self.matrix[i][3]<90 and self.matrix[i][3]>=80):
                        self.matrix[i][4]="A"
                    if(self.matrix[i][3]<80 and self.matrix[i][3]>=75):
                        self.matrix[i][4]="B+"
                    if(self.matrix[i][3]<75 and self.matrix[i][3]>=70):
                        self.matrix[i][4]="B"
                    if(self.matrix[i][3]<70 and self.matrix[i][3]>=60):
                        self.matrix[i][4]="C"
                    if(self.matrix[i][3]<60 and self.matrix[i][3]>=50):
                        self.matrix[i][4]="B"
                    if(self.matrix[i][3]<50):
                        self.matrix[i][4]="F"


student = [[None] * 5 for _ in range(5)]

student[0][0] = "umamah"
student[0][1] = "21L-1858"
student[0][2] = "AI"
student[0][3] = 80

student[1][0] = "waleed"
student[1][1] = "21L-5248"
student[1][2] = "AI"
student[1][3] = 60

student[2][0] = "harris"
student[2][1] = "21L-4898"
student[2][2] = "NLP"
student[2][3] = 95

student[3][0] = "abdull"
student[3][1] = "21L-0098"
student[3][2] = "PDC"
student[3][3] = 40

student[4][0] = "ayesha"
student[4][1] = "21L-9988"
student[4][2] = "SE"
student[4][3] = 75

s = Student(student)
# s.DisplayMatrix()
s.CalcGrade()
s.DisplayMatrix()

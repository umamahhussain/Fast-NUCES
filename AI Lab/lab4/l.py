import copy
import sys

def secondmin(a,b,c,d):
    array=[a,b,c,d]
    array.sort()
    return array[1]


def DisplayPuzzle(maze):
    for i in range(len(maze)):
        for j in range(len(maze[i])):
            print(maze[i][j], "       ", end="")
        print("\n")


def CalcHeuristic(initialmaze, finalmaze):
    heuristic = 0
    for i in range(len(initialmaze)):
        for j in range(len(initialmaze[i])):
            if initialmaze[i][j] != " ":
                current_tile = initialmaze[i][j]
                # Find the position of the current tile in the final state
                for m in range(len(finalmaze)):
                    for n in range(len(finalmaze[m])):
                        if finalmaze[m][n] == current_tile:
                            goal_row, goal_col = m, n
                            break
                # Calculate Manhattan distance and add to heuristic
                heuristic += abs(i - goal_row) + abs(j - goal_col)
    return heuristic



def A_Star(initialmaze,finalmaze):
     index1=0
     index2=0
     pathcost=0
     moves=[]
     lastmove="0"
     

     while(CalcHeuristic(initialmaze,finalmaze)!=0):
         for i in range(len(initialmaze)):
              for j in range(len(initialmaze[i])):
                  if(initialmaze[i][j]==" "):
                      index1=i
                      index2=j
                      break
         if len(moves)!=0:
          lastmove=moves.pop()
        
         if(index1==0 and index2==0):
             tempmaze1=copy.deepcopy(initialmaze)
             tempmaze2=copy.deepcopy(initialmaze)

             temp=tempmaze1[index1][index2]
             tempmaze1[index1][index2]=tempmaze1[index1+1][index2]
             tempmaze1[index1+1][index2]=temp
             hval1=CalcHeuristic(tempmaze1,finalmaze)+pathcost
             print("Heuristic 1: ",hval1)

             temp=tempmaze2[index1][index2]
             tempmaze2[index1][index2]=tempmaze2[index1][index2+1]
             tempmaze2[index1][index2+1]=temp
             hval2=CalcHeuristic(tempmaze2,finalmaze)+pathcost
             print("Heuristic 2: ",hval2)
             flag=0
             mini=min(hval1,hval2)
             
             while(flag!=1):
              if(mini==hval1 and lastmove!="up"):
                 initialmaze=tempmaze1.copy()
                 print("Heuristic 1: Moving Down\n")
                 index1=index1+1
                 moves.append("down")
                 flag=1
              elif(mini==hval2 and lastmove!="left"):
                 initialmaze=tempmaze2.copy()
                 print("Heuristic 2: Moving Right\n")
                 index2=index2+1
                 moves.append("right")
                 flag=1
              
              if(flag==0):
                  mini=secondmin(hval1,hval2,sys.maxsize,sys.maxsize)

             DisplayPuzzle(initialmaze)

         
         
         elif(index1==0 and index2==1):
             tempmaze1=copy.deepcopy(initialmaze)
             tempmaze2=copy.deepcopy(initialmaze)
             tempmaze3=copy.deepcopy(initialmaze)

             temp=tempmaze1[index1][index2]
             tempmaze1[index1][index2]=tempmaze1[index1+1][index2]
             tempmaze1[index1+1][index2]=temp
             hval1=CalcHeuristic(tempmaze1,finalmaze)+pathcost
             print("Heuristic 1: ",hval1)

             temp=tempmaze2[index1][index2]
             tempmaze2[index1][index2]=tempmaze2[index1][index2-1]
             tempmaze2[index1][index2-1]=temp
             hval2=CalcHeuristic(tempmaze2,finalmaze)+pathcost
             print("Heuristic 2: ",hval2)

             temp=tempmaze3[index1][index2]
             tempmaze3[index1][index2]=tempmaze3[index1][index2+1]
             tempmaze3[index1][index2+1]=temp
             hval3=CalcHeuristic(tempmaze3,finalmaze)+pathcost
             print("Heuristic 3: ",hval3)

             flag=0

             mini=min(hval1,hval2,hval3)

             while(flag!=1):
                if(mini==hval1 and lastmove!="up"):
                    initialmaze=tempmaze1.copy()
                    index1=index1+1
                    print("Heuristic 1: Moved Down\n")
                    moves.append("down")
                    flag=1
                 
                elif(mini==hval2 and lastmove!="right"):
                    initialmaze=tempmaze2.copy()
                    index2=index2-1
                    print("Heuristic 2: Moved left\n")
                    moves.append("left")
                    flag=1

                elif(mini==hval3 and lastmove!="left"):
                    initialmaze=tempmaze3.copy()
                    index2=index2+1
                    print("Heuristic 3: Moved Right\n")
                    moves.append("right")
                    flag=1
                
                if(flag==0):
                  mini=secondmin(hval1,hval2,hval3,sys.maxsize)

             DisplayPuzzle(initialmaze)
         
         
         
         elif(index1==0 and index2==2):
             tempmaze1=copy.deepcopy(initialmaze)
             tempmaze2=copy.deepcopy(initialmaze)

            #move down
             temp=tempmaze1[index1][index2]
             tempmaze1[index1][index2]=tempmaze1[index1+1][index2]
             tempmaze1[index1+1][index2]=temp
             hval1=CalcHeuristic(tempmaze1,finalmaze)+pathcost
             print("Heuristic 1: ",hval1)

            #move left
             temp=tempmaze2[index1][index2]
             tempmaze2[index1][index2]=tempmaze2[index1][index2-1]
             tempmaze2[index1][index2-1]=temp
             hval2=CalcHeuristic(tempmaze2,finalmaze)+pathcost
             print("Heuristic 2: ",hval2)

             mini=min(hval1,hval2)
             flag=0
             while(flag!=1):
              if(mini==hval1 and lastmove!="up"):
                 initialmaze=tempmaze1.copy()
                 index1=index1+1
                 print("Heuristic 1: Moved Down")
                 moves.append("down")
              elif(mini==hval2 and lastmove!="right"):
                 initialmaze=tempmaze2.copy()
                 index2=index2-1
                 print("Heuristic 2: Moved Left")
                 moves.append("left")
              if(flag==0):
                  mini=secondmin(hval1,hval2,sys.maxsize,sys.maxsize)
             DisplayPuzzle(initialmaze)

         
         
         elif(index1==1 and index2==0):
             tempmaze1=copy.deepcopy(initialmaze)
             tempmaze2=copy.deepcopy(initialmaze)
             tempmaze3=copy.deepcopy(initialmaze)

            #move down
             temp=tempmaze1[index1][index2]
             tempmaze1[index1][index2]=tempmaze1[index1+1][index2]
             tempmaze1[index1+1][index2]=temp
             hval1=CalcHeuristic(tempmaze1,finalmaze)+pathcost
             print("Heuristic 1: ",hval1)

            #move right
             temp=tempmaze2[index1][index2]
             tempmaze2[index1][index2]=tempmaze2[index1][index2+1]
             tempmaze2[index1][index2+1]=temp
             hval2=CalcHeuristic(tempmaze2,finalmaze)+pathcost
             print("Heuristic 2: ",hval2)

            #move up
             temp=tempmaze3[index1][index2]
             tempmaze3[index1][index2]=tempmaze3[index1-1][index2]
             tempmaze3[index1-1][index2]=temp
             hval3=CalcHeuristic(tempmaze3,finalmaze) +pathcost
             print("Heuristic 3: ",hval3)

             
             mini=min(hval1,hval2,hval3)
             flag=0

             while(flag!=1):
                if(mini==hval1 and lastmove!="up"):
                    initialmaze=tempmaze1.copy()
                    index1=index1+1
                    print("Heuristic 1: Moved Down")
                    moves.append("down")
                    flag=1
                elif(mini==hval2 and lastmove!="left"):
                    initialmaze=tempmaze2.copy()
                    index2=index2+1
                    print("Heuristic 2: Moved Right")
                    moves.append("right")
                    flag=1
                elif(mini==hval3 and lastmove!="down"):
                    initialmaze=tempmaze3.copy()
                    index1=index1-1
                    print("Heuristic 3: Moved Up")
                    moves.append("up")
                    flag=1
                if(flag==0):
                    mini=secondmin(hval1,hval2,hval3,sys.maxsize)
             DisplayPuzzle(initialmaze)

         
         
         elif(index1==1 and index2==1):
             tempmaze1=copy.deepcopy(initialmaze)
             tempmaze2=copy.deepcopy(initialmaze)
             tempmaze3=copy.deepcopy(initialmaze)
             tempmaze4=copy.deepcopy(initialmaze)

            #move down
             temp=tempmaze1[index1][index2]
             tempmaze1[index1][index2]=tempmaze1[index1+1][index2]
             tempmaze1[index1+1][index2]=temp
             hval1=CalcHeuristic(tempmaze1,finalmaze)+pathcost
             print("Heuristic 1: ",hval1)

            #move right
             temp=tempmaze2[index1][index2]
             tempmaze2[index1][index2]=tempmaze2[index1][index2+1]
             tempmaze2[index1][index2+1]=temp
             hval2=CalcHeuristic(tempmaze2,finalmaze)+pathcost
             print("Heuristic 2: ",hval2)

            #move up
             temp=tempmaze3[index1][index2]
             tempmaze3[index1][index2]=tempmaze3[index1-1][index2]
             tempmaze3[index1-1][index2]=temp
             hval3=CalcHeuristic(tempmaze3,finalmaze)+pathcost
             print("Heuristic 3: ",hval3)

            #move left
             temp=tempmaze4[index1][index2]
             tempmaze4[index1][index2]=tempmaze4[index1][index2-1]
             tempmaze4[index1][index2-1]=temp
             hval4=CalcHeuristic(tempmaze4,finalmaze)+pathcost
             print("Heuristic 4: ",hval4)

             mini=min(hval1,hval2,hval3,hval4)
             flag=0

             while(flag!=1):
                if(mini==hval1 and lastmove!="up"):
                    initialmaze=tempmaze1.copy()
                    index1=index1+1
                    flag=1
                    print("Heuristic 1: Moved Down")
                    moves.append("down")
                elif(mini==hval2 and lastmove!="left"):
                    initialmaze=tempmaze2.copy()
                    index2=index2+1
                    flag=1
                    print("Heuristic 2: Moved Right")
                    moves.append("right")
                elif(mini==hval4 and lastmove!="right"):
                    index2=index2-1
                    initialmaze=tempmaze4.copy()
                    print("Heuristic 4: Moved left")
                    flag=1
                    moves.append("left")
                elif(mini==hval3 and lastmove!="down"):
                    index1=index1-1
                    flag=1
                    initialmaze=tempmaze3.copy()
                    print("Heuristic 3:Moved up")
                    moves.append("up")
                if(flag==0):
                  mini=secondmin(hval1,hval2,hval3,hval4)   

             DisplayPuzzle(initialmaze)
         
         
         
         elif(index1==1 and index2==2):
             tempmaze1=copy.deepcopy(initialmaze)
             tempmaze2=copy.deepcopy(initialmaze)
             tempmaze3=copy.deepcopy(initialmaze)

            #move down
             temp=tempmaze1[index1][index2]
             tempmaze1[index1][index2]=tempmaze1[index1+1][index2]
             tempmaze1[index1+1][index2]=temp
             hval1=CalcHeuristic(tempmaze1,finalmaze)+pathcost
             print("Heuristic 1: ",hval1)

            #move left
             temp=tempmaze2[index1][index2]
             tempmaze2[index1][index2]=tempmaze2[index1][index2-1]
             tempmaze2[index1][index2-1]=temp
             hval2=CalcHeuristic(tempmaze2,finalmaze)+pathcost
             print("Heuristic 2: ",hval2)

            #move up
             temp=tempmaze3[index1][index2]
             tempmaze3[index1][index2]=tempmaze3[index1-1][index2]
             tempmaze3[index1-1][index2]=temp
             hval3=CalcHeuristic(tempmaze3,finalmaze)+pathcost
             print("Heuristic 3: ",hval3)


             mini=min(hval1,hval2,hval3)
             flag=0

             while(flag!=1):
                if(mini==hval1 and lastmove!="up"):
                    initialmaze=tempmaze1.copy()
                    index1=index1+1
                    print("Heuristic 1: Moved Down")
                    moves.append("down")
                    flag=1
                elif(mini==hval2 and lastmove!="right"):
                    index2=index2-1
                    initialmaze=tempmaze2.copy()
                    print("Heuristic 2: Moved Left")
                    moves.append("left")
                    flag=1
                elif(mini==hval3 and lastmove!="down"):
                    initialmaze=tempmaze3.copy()
                    flag=1
                    index1=index1-1
                    print("Heuristic 3:Moved Up")
                    moves.append("up")
                if(flag==0):
                  mini=secondmin(hval1,hval2,hval3,sys.maxsize)
             DisplayPuzzle(initialmaze)

         elif(index1==2 and index2==0):
             tempmaze1=copy.deepcopy(initialmaze)
             tempmaze2=copy.deepcopy(initialmaze)

            #move up
             temp=tempmaze1[index1][index2]
             tempmaze1[index1][index2]=tempmaze1[index1-1][index2]
             tempmaze1[index1-1][index2]=temp
             hval1=CalcHeuristic(tempmaze1,finalmaze)+pathcost
             print("Heuristic 1: ",hval1)

            #Move right
             temp=tempmaze2[index1][index2]
             tempmaze2[index1][index2]=tempmaze2[index1][index2+1]
             tempmaze2[index1][index2+1]=temp
             hval2=CalcHeuristic(tempmaze2,finalmaze)+pathcost
             print("Heuristic 2: ",hval2)

             flag=0
             mini=min(hval1,hval2)

             while(flag!=1):
                if(mini==hval1 and lastmove!="down"):
                    initialmaze=tempmaze1.copy()
                    index1=index1-1
                    print("Heuristic 1: Moving Up\n")
                    moves.append("up")
                    flag=1
                elif(mini==hval2 and lastmove!="left"):
                    initialmaze=tempmaze2.copy()
                    index2=index2+1
                    flag=1
                    print("Heuristic 2: Moving Right\n")
                    moves.append("right")
                if(flag==0):
                  mini=secondmin(hval1,hval2,sys.maxsize,sys.maxsize)
             DisplayPuzzle(initialmaze)


         elif(index1==2 and index2==1):
             tempmaze1=copy.deepcopy(initialmaze)
             tempmaze2=copy.deepcopy(initialmaze)
             tempmaze3=copy.deepcopy(initialmaze)

            #move up
             temp=tempmaze1[index1][index2]
             tempmaze1[index1][index2]=tempmaze1[index1-1][index2]
             tempmaze1[index1-1][index2]=temp
             hval1=CalcHeuristic(tempmaze1,finalmaze)+pathcost
             print("Heuristic 1: ",hval1)

            #move left
             temp=tempmaze2[index1][index2]
             tempmaze2[index1][index2]=tempmaze2[index1][index2-1]
             tempmaze2[index1][index2-1]=temp
             hval2=CalcHeuristic(tempmaze2,finalmaze)+pathcost
             print("Heuristic 2: ",hval2)

            #move right
             temp=tempmaze3[index1][index2]
             tempmaze3[index1][index2]=tempmaze3[index1][index2+1]
             tempmaze3[index1][index2+1]=temp
             hval3=CalcHeuristic(tempmaze3,finalmaze)+pathcost
             print("Heuristic 3: ",hval3)

             mini=min(hval1,hval2,hval3)
             flag=0

             while(flag!=1):
                if(mini==hval1 and lastmove!="down"):
                    initialmaze=tempmaze1.copy()
                    index1=index1-1
                    print("Heuristic 1: Moved Up\n")
                    flag=1
                    moves.append("up")
                elif(mini==hval2 and lastmove!="right"):
                    index2=index2-1
                    initialmaze=tempmaze2.copy()
                    flag=1
                    print("Heuristic 2: Moved Left\n")
                    moves.append("left")
                elif(mini==hval3 and lastmove!="left"):
                    initialmaze=tempmaze3.copy()
                    index2=index2+1
                    print("Heuristic 3: Moved Right\n")
                    flag=1
                    moves.append("right")
                if(flag==0):
                  mini=secondmin(hval1,hval2,hval3,sys.maxsize)
             DisplayPuzzle(initialmaze)
         

         elif(index1==2 and index2==2):
             tempmaze1=copy.deepcopy(initialmaze)
             tempmaze2=copy.deepcopy(initialmaze)

            #move up
             temp=tempmaze1[index1][index2]
             tempmaze1[index1][index2]=tempmaze1[index1-1][index2]
             tempmaze1[index1-1][index2]=temp
             hval1=CalcHeuristic(tempmaze1,finalmaze)+pathcost
             print("Heuristic 1: ",hval1)

            #move left
             temp=tempmaze2[index1][index2]
             tempmaze2[index1][index2]=tempmaze2[index1][index2-1]
             tempmaze2[index1][index2-1]=temp
             hval2=CalcHeuristic(tempmaze2,finalmaze)+pathcost
             print("Heuristic 2: ",hval2)

             mini=min(hval1,hval2)
             flag=0
             
             while(flag!=1):
                if(mini==hval1 and lastmove!="down"):
                    initialmaze=tempmaze1.copy()
                    index1=index1-1
                    print("Heuristic 1: Moved Up")
                    flag=1
                    moves.append("up")
                elif(mini==hval2 and lastmove!="right"):
                    initialmaze=tempmaze2.copy()
                    index2=index2-1
                    print("Heuristic 2: Moved Left")
                    flag=1
                    moves.append("left")
                if(flag==0):
                    mini=secondmin(hval1,hval2,sys.maxsize,sys.maxsize)
             DisplayPuzzle(initialmaze)
         pathcost=pathcost+1
      

initial = [[1, 2, 3], [8, 6, 4], [7, " ", 5]]
final = [[3, 1, 2], [8, " ", 4], [7, 6, 5]]
DisplayPuzzle(initial)
print("The A* Algorithm is about to start:\n")
A_Star(initial, final)
print("\nThe final state is as follows: \n")
DisplayPuzzle(final)



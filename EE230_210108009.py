# Python3 code to implement Freivald’s Algorithm
import random
N = int(input("enter value of N:"))
# Function to check if ABx = Cx
def freivald(a, b, c) :
	
	# Generate a random vector
	r = [0] * N
	
	for i in range(0, N) :
		r[i] = (int)(random.randrange(509090009) % 2)

	# Now compute B*r for evaluating
	# expression A * (B*r) - (C*r)
	br = [0] * N
	
	for i in range(0, N) :
		for j in range(0, N) :
			br[i] = br[i] + b[i][j] * r[j]

	# Now compute C*r for evaluating
	# expression A * (B*r) - (C*r)
	cr = [0] * N
	for i in range(0, N) :
		for j in range(0, N) :
			cr[i] = cr[i] + c[i][j] * r[j]

	# Now compute A* (B*r) for evaluating
	# expression A * (B*r) - (C*r)
	axbr = [0] * N
	for i in range(0, N) :
		for j in range(0, N) :
			axbr[i] = axbr[i] + a[i][j] * br[j]

	# Finally check if value of expression
	# A * (B*r) - (C*r) is 0 or not
	for i in range(0, N) :
		if (axbr[i] - cr[i] != 0) :
			return False
			
	return True

# Runs k iterations Freivald. The value
# of k determines accuracy. Higher value
# means higher accuracy.
def isProduct(a, b, c, k) :
	
	for i in range(0, k) :
		if (freivald(a, b, c) == False) :
			return False
	return True
R = int(input("Enter the number of rows:"))
C = int(input("Enter the number of columns:"))
# Driver code
a= []
print("Enter the entries rowwise such that each line has only one element:")
# # For user input
for i in range(R):		 #  for loop for row entries
	mat =[]
	for j in range(C):	 #  for loop for column entries
		mat.append(int(input()))
	a.append(mat)
R1 = int(input("Enter the number of rows:"))
C1 = int(input("Enter the number of columns:"))
# # Initialize matrix
b = []
print("Enter the entries rowwise such that each line has only one element:")

# For user input
for i in range(R1):  #  for loop for row entries
    mat = []
    for j in range(C1):  #  for loop for column entries
        mat.append(int(input()))
    b.append(mat)




# Initialize matrix
c = []
print("Enter the entries of product matrix rowwise :")

# For user input
for i in range(R):  # for loop for row entries
    mat = []
    for j in range(C1):  #  for loop for column entries
       mat.append(int(input()))
    c.append(mat)
k = int(input("enter no. of trials:"))

if (isProduct(a, b, c, k)) :
	print("Yes")
else :
	print("No")


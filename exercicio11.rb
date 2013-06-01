require 'matrix'

s = "cassio".size

A = Matrix[[1, 2],
           [3, 4]]

B = Matrix[[5, 6],
           [7, 8]]

C = Matrix[[s, 2*s],
           [s, 2*s],
           [s, 2*s],
           [s, 2*s]]

puts "a: S",   s
# => 6
puts "b: A+B", A + B
# => [[  6,   8],
#     [ 10,  12]]
puts "c: A*B", A * B
# => [[ 19,  22],
#     [ 43,  50]]
puts "d: 5*A", 5 * A
# => [[  5,  10],
#     [ 15,  20]]
puts "e: B*t(A)", B * A.transpose
# => [[ 17,  39],
#     [ 23,  53]]
puts "f: A*C", A * C rescue puts "f: Matrix dimension mismatch"
# => "f: Matrix dimension mismatch"
puts "g: C*B", C * B
# => [[114, 132],
#     [114, 132],
#     [114, 132],
#     [114, 132]]

class RGB

  def self.[](r, g, b)

    return [r, g, b]
  end
end

class CMYK
  def self.[](c, m, y ,k)

    # naive formula
    r = 255 * (100-c) / 100 * (100-k) / 100
    g = 255 * (100-m) / 100 * (100-k) / 100
    b = 255 * (100-y) / 100 * (100-k) / 100

    return [r, g, b]
  end
end

def distance(colour1, colour2)

  sides_squared = colour1.zip(colour2).map { |colour| colour.reduce(&:+).abs }
  hipotenuse = Math.sqrt(sides_squared.reduce(&:+))
  return hipotenuse
end

c1 =  RGB[  0,   0,   0]
c2 =  RGB[255, 255, 255]
c3 =  RGB[255,   0,   0]
c4 =  RGB[  0, 255,   0]
c5 = CMYK[  0,   0,   0, 100]

puts "distance 1 and 2:", distance(c1, c2)
# => 27.65863337187866
puts "distance 1 and 3:", distance(c1, c3)
# => 15.968719422671311
puts "distance 3 and 4:", distance(c3, c4)
# => 22.58317958127243
puts "distance 1 and 5:", distance(c1, c5)
# => 0.0

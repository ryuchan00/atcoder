# 探した中だとこれがもっとも速いのだった。
a = gets.to_i
b = gets.to_i
c = gets.to_i
x = gets.to_i
count = 0
0.upto(a) do |i|
  break if i * 500 > x
  0.upto(b) do |s|
    break if i * 500 + s * 100 > x
    0.upto(c) do |t|
      break if i * 500 + s * 100 + t * 50 > x
      count += 1 if i * 500 + s * 100 + t * 50 == x
    end
  end
end
puts count
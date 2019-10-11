A = gets.to_i
B = gets.to_i
C = gets.to_i
X = gets.to_i
ans = 0

0.upto(A) do |i|
  break if i * 500 > X
  if X == i * 500
    ans += 1
    break
  end
  0.upto(B) do |j|
    # n:残金
    n = X - i * 500
    if j > 0 && n == (j * 100)
      ans += 1
    end
    n = n - j * 100
    if n > 0 && n / 50 <= C
      ans += 1
    end
  end
end

puts ans

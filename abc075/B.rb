# https://atcoder.jp/contests/abc075/tasks/abc075_b


H, W = gets.split.map(&:to_i)
Ss = Array.new(H) { gets.chomp }
ans = Array.new(H) { '#' * W }

# 行の繰り返し
H.times do |y|
  # 列の繰り返し
  W.times do |x|
    bom = 0

    # 爆弾の場合
    if Ss[y][x] == '#'
      next
    end

    # 時計回りに見ていく
    # 左上
    if y != 0 && x != 0
      bom += 1 if Ss[y - 1][x - 1] == '#'
    end

    # 上
    if y != 0
      bom += 1 if Ss[y - 1][x] == '#'
    end

    # 右上
    if y != 0 && x != W - 1
      bom += 1 if Ss[y - 1][x + 1] == '#'
    end

    # 右
    if x != W - 1
      bom += 1 if Ss[y][x + 1] == '#'
    end

    # 右下
    if y != H - 1 && x != W - 1
      bom += 1 if Ss[y + 1][x + 1] == '#'
    end

    # 下
    if y != H - 1
      bom += 1 if Ss[y + 1][x] == '#'
    end

    # 左下
    if y != H - 1 && x != 0
      bom += 1 if Ss[y + 1][x - 1] == '#'
    end

    # 左
    if x != 0
      bom += 1 if Ss[y][x - 1] == '#'
    end

    ans[y][x] = bom.to_s
  end
end

puts ans

#      -----
#      .....
#      .#.#.
#      .....
#      -----

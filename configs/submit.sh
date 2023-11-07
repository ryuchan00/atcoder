#!/bin/bash

submit_file=$1 # relative file path (${service_name}/${contest_id}/${problem_id}/main.cpp)

service_name=${submit_file%%/*}
contest_id=$(basename ${submit_file%/*/*})
problem_id=$(basename ${submit_file%/*})

case "$service_name" in
"AtCoder")
  problem_url="https://atcoder.jp/contests/${contest_id}/tasks/${problem_id}"
  ;;
"Codeforces")
  problem_url="https://codeforces.com/contest/${contest_id}/problem/${problem_id}"
  ;;
esac

pipenv run oj s -y ${problem_url} ${submit_file}

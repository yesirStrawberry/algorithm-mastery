import os
import subprocess
import time
import requests

# /tmp/zagabi 디렉토리로 이동하여 서버 구동
zagabi_dir = "/tmp/zagabi"

env = os.environ.copy()
env["HOST"] = "0.0.0.0"
env["PORT"] = "12014"

# /tmp/zagabi 경로에서 npm start 실행
server_process = subprocess.Popen(
    "npm start",
    shell=True,
    cwd=zagabi_dir,
    env=env
)

time.sleep(3)

try:
    res = requests.get("http://127.0.0.1:12014/health")
    print("\n[성공] 서버 상태:", res.json())
except Exception as e:
    print("\n[실패] 서버 연결 실패:", e)

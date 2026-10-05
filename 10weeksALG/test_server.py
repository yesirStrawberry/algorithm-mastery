import os
import subprocess
import time
import requests

zagabi_dir = "/tmp/zagabi"

# 1. /tmp/zagabi 폴더가 없으면 자동으로 클론 및 npm install 수행
if not os.path.exists(zagabi_dir):
    print("[안내] /tmp/zagabi 폴더가 없어 새로 설치를 진행합니다...")
    subprocess.run(["git", "clone", "https://github.com/wnghdcjfe/zagabi.git", zagabi_dir], check=True)
    subprocess.run(["npm", "install"], cwd=zagabi_dir, check=True)

env = os.environ.copy()
env["HOST"] = "0.0.0.0"
env["PORT"] = "12014"

# 2. zagabi 서버 실행
server_process = subprocess.Popen(
    "npm start",
    shell=True,
    cwd=zagabi_dir,
    env=env
)

time.sleep(3)

# 3. 헬스체크
try:
    res = requests.get("http://127.0.0.1:12014/health")
    print("\n[성공] 서버 상태:", res.json())
except Exception as e:
    print("\n[실패] 서버 연결 실패:", e)
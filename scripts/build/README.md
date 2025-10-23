# Raspberry Pi 5 Docker Build Scripts

Raspberry Pi 5 (arm64)용 medusa 프로젝트를 Docker를 이용해 빌드하고 실행하는 스크립트입니다.

## 필요 사항

- Docker 설치
- VCPKG_ROOT 환경변수 설정 (또는 Docker 내부에서 자동 설치됨)

## 빌드 방법

### 기본 빌드 (Release)

```bash
./scripts/build/build-rpi5.sh
```

### 다양한 빌드 옵션

```bash
# Debug 빌드
./scripts/build/build-rpi5.sh --preset arm64-rpi5-ninja-debug

# RelWithDebInfo 빌드
./scripts/build/build-rpi5.sh --preset arm64-rpi5-ninja-relinfo

# 캐시 없이 빌드 (처음부터 다시 빌드)
./scripts/build/build-rpi5.sh --no-cache

# Docker 이미지만 빌드 (프로젝트 컴파일 생략)
./scripts/build/build-rpi5.sh --build-only
```

### 빌드 결과물

빌드가 완료되면 `build-output/` 디렉토리에 다음과 같이 저장됩니다:
```
build-output/
├── build/
│   └── arm64-rpi5-ninja/
│       ├── debug/
│       ├── release/
│       └── relinfo/
└── install/
    └── arm64-rpi5-ninja/
        ├── debug/
        ├── release/
        └── relinfo/
```

## 실행 방법

### 방법 1: Docker 컨테이너에서 실행 (권장)

#### Interactive Shell 실행
```bash
./scripts/build/run-rpi5.sh
```

컨테이너 내부에서:
```bash
# Release 버전 실행
/app/build/arm64-rpi5-ninja/release/sample/medusa_sample

# Debug 버전 실행
/app/build/arm64-rpi5-ninja/debug/sample/medusa_sample
```

#### 직접 실행
```bash
# Release 버전 실행
./scripts/build/run-rpi5.sh /app/build/arm64-rpi5-ninja/release/sample/medusa_sample

# Debug 버전 실행
./scripts/build/run-rpi5.sh --build-type debug /app/build/arm64-rpi5-ninja/debug/sample/medusa_sample

# Background에서 실행
./scripts/build/run-rpi5.sh --detach /app/build/arm64-rpi5-ninja/release/sample/medusa_sample
```

### 방법 2: 추출된 파일로 실행

빌드 스크립트는 자동으로 결과물을 `build-output/`에 추출합니다.

Raspberry Pi 5로 복사:
```bash
# build-output 디렉토리를 Raspberry Pi로 복사
scp -r build-output/ user@raspberrypi:/home/user/medusa/

# Raspberry Pi에서 실행
ssh user@raspberrypi
cd /home/user/medusa/build-output/build/arm64-rpi5-ninja/release/sample/
./medusa_sample
```

### 방법 3: Docker 명령어로 직접 실행

```bash
# Interactive shell
docker run --rm -it medusa-rpi5-builder:latest /bin/bash

# 직접 실행
docker run --rm medusa-rpi5-builder:latest /app/build/arm64-rpi5-ninja/release/sample/medusa_sample
```

## 빌드 프리셋 설명

| 프리셋 | 설명 | 최적화 |
|--------|------|--------|
| arm64-rpi5-ninja-debug | 디버그 빌드 | 최적화 없음, 디버그 심볼 포함 |
| arm64-rpi5-ninja-release | 릴리즈 빌드 | -O2 최적화, 디버그 심볼 없음 |
| arm64-rpi5-ninja-relinfo | 릴리즈 + 디버그 정보 | -O2 최적화, 디버그 심볼 포함 |

## 문제 해결

### Docker 이미지를 찾을 수 없음
```bash
./scripts/build/build-rpi5.sh
```
먼저 이미지를 빌드해야 합니다.

### vcpkg 의존성 빌드 실패
```bash
# 캐시를 지우고 다시 빌드
./scripts/build/build-rpi5.sh --no-cache
```

### 빌드된 바이너리가 실행되지 않음
Raspberry Pi 5의 아키텍처를 확인하세요:
```bash
uname -m  # x86_64 또는 aarch64
```

## 고급 사용법

### 커스텀 Docker 태그
```bash
./scripts/build/build-rpi5.sh --tag v1.0.0
./scripts/build/run-rpi5.sh --tag v1.0.0
```

### Docker 이미지 크기 확인
```bash
docker images medusa-rpi5-builder
```

### 빌드 로그 확인
빌드 실패 시 Docker 빌드 로그를 확인:
```bash
./scripts/build/build-rpi5.sh 2>&1 | tee build.log
```

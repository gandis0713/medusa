# Git Commit Message Instructions for Medusa Project

## Language
- **한글**로 커밋 메시지를 작성하세요.

## Format

```
<제목>

<본문>
```

### 제목 (Title)
- **50자 이내**로 작성
- 변경사항을 명확하고 간결하게 요약
- 마침표(`.`) 없이 작성
- 예시:
  - `Vulkan ICD 구현 및 샘플 애플리케이션 추가`
  - `Docker 빌드 스크립트 및 환경 설정 추가`
  - `medusa_utils를 공유 라이브러리로 변경`

### 본문 (Body)
- 제목과 본문 사이에 **빈 줄 한 줄** 추가
- 변경사항을 **불릿 포인트**(`-`)로 나열. 변경사항은 모두 포함. 생략 금지
- 각 항목은 **구체적인 변경사항**을 설명
- **왜(why)** 변경했는지보다 **무엇을(what)** 변경했는지에 집중
- 파일명, 함수명, 클래스명 등 구체적인 정보 포함

#### 예시:
```
Vulkan ICD 구현 및 샘플 애플리케이션 추가

- medusa_icd.json.in 파일 생성
- CMakeLists.txt 수정: 공유 라이브러리로 medusa 생성
- vk_instance 클래스 구현 및 관련 파일 추가
- vk_api.cpp 및 vk_instance.cpp 파일 추가
- 샘플 애플리케이션에서 Vulkan 인스턴스 생성 및 파괴 로직 추가
```

## 변경 유형별 예시

### 기능 추가 (Feature)
```
vkEnumerateInstanceExtensionProperties 함수 구현

- medusa_EnumerateInstanceExtensionProperties 함수 추가
- medusa_EnumerateInstanceLayerProperties 함수 추가
- vk_icdGetInstanceProcAddr에서 새 함수 반환 로직 추가
- 현재는 0개의 확장/레이어 반환 (최소 구현)
```

### 버그 수정 (Bug Fix)
```
ICD manifest 경로 오류 수정

- medusa_icd.json.in의 library_path를 상대 경로로 변경
- 절대 경로 사용 시 Docker 컨테이너에서 파일을 찾지 못하는 문제 해결
- "./libmedusa_icd.so" 형식으로 변경
```

### 리팩토링 (Refactor)
```
빌드 스크립트 디렉토리 구조 개선

- run-rpi5.sh를 scripts/build에서 scripts/run으로 이동
- run-local.sh 스크립트 추가 (로컬 실행용)
- README.md의 경로 참조 업데이트
```

### 문서화 (Documentation)
```
프로젝트 문서 및 태스크 스펙 추가

- CLAUDE.md 파일 생성: 프로젝트 구조 및 빌드 방법 설명
- tasks/medusa_utils_shared_library.md 추가
- tasks/implement_enumerate_functions.md 추가
```

### 설정 변경 (Configuration)
```
medusa_utils에 Position Independent Code 설정 추가

- common/utils/CMakeLists.txt: POSITION_INDEPENDENT_CODE ON 설정
- 공유 라이브러리 링크 시 발생하는 -fPIC 에러 해결
```

## 주의사항

1. **구체적으로 작성**: "수정함", "변경함" 대신 정확히 무엇을 수정했는지 명시
2. **기술적 용어 사용**: 파일명, 함수명, 변수명 등을 정확히 기재
3. **변경 범위**: 여러 파일/모듈을 수정했다면 각각 별도 항목으로 나열
4. **일관성 유지**: 프로젝트 전체에서 비슷한 형식 사용

## 피해야 할 표현

❌ 나쁜 예:
```
코드 수정

- 몇 가지 수정
- 버그 수정
- 개선
```

✅ 좋은 예:
```
Vulkan loader 환경변수 설정 추가

- scripts/run/run-rpi5.sh: VK_ICD_FILENAMES 환경변수 설정
- scripts/run/run-rpi5.sh: LD_LIBRARY_PATH에 ICD 라이브러리 경로 추가
- scripts/run/run-rpi5.sh: VK_LOADER_DEBUG=all로 디버그 로그 활성화
```

## 특별한 경우

### WIP (Work in Progress)
작업 중인 커밋의 경우:
```
WIP: vkEnumeratePhysicalDevices 구현 중

- vk_physical_device 클래스 스켈레톤 추가
- TODO: V3D 디바이스 열거 로직 구현 필요
```

### 초기 커밋
```
프로젝트 초기 설정

- CMake 프로젝트 구조 생성
- vcpkg 의존성 설정
- Docker 빌드 환경 구성
```

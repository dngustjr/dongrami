# My AI Engineering Path
<!-- Managed by the ai-engineering-from-scratch learning skills.
     Repo: https://github.com/rohitg00/ai-engineering-from-scratch -->

## Mission
현재 공동구매 사업을 하고 있는데 공동구매 업무를 AI에이전트 팀으로 자동화 시키고 싶음.
Build goal: AI 에이전트

## Placement
- Date: 2026-10-23
- Score: self-selected
  <!-- Earlier placement quiz: 3/10 (Math & Statistics 1/2, Classical ML 1/2, Deep Learning 0/2, NLP & Transformers 0/2, Applied AI 1/2). Learner chose to start at Phase 14 and go back to earlier phases when stuck. -->
- Entry point: Phase 14: Agent Engineering
- Pace: ~10/week

## Path
| Phase | Name | Status | Est. hours |
|-------|------|--------|------------|
| 0 | Setup & Tooling | Skip | -- |
| 1 | Math Foundations | Skip | -- |
| 2 | ML Fundamentals | Skip | -- |
| 3 | Deep Learning Core | Skip | -- |
| 4 | Computer Vision | Skip | -- |
| 5 | NLP — Foundations to Advanced | Skip | -- |
| 6 | Speech & Audio | Skip | -- |
| 7 | Transformers Deep Dive | Skip | -- |
| 8 | Generative AI | Skip | -- |
| 9 | Reinforcement Learning | Skip | -- |
| 10 | LLMs from Scratch | Skip | -- |
| 11 | LLM Engineering | Skip | -- |
| 12 | Multimodal AI | Skip | -- |
| 13 | Tools & Protocols | Skip | -- |
| 14 | Agent Engineering | Do | 55 |
| 15 | Autonomous Systems | Do | 20 |
| 16 | Multi-Agent & Swarms | Do | 28 |
| 17 | Infrastructure & Production | Do | 34 |
| 18 | Ethics, Safety & Alignment | Do | 31 |
| 19 | Capstone Projects | Do | 620 |
| | **Total (Review + Do)** | | **788** |

## Progress log
| Date | Lesson | Quiz | Note |
|------|--------|------|------|
| 2026-10-23 | 14/01-the-agent-loop | 2/2 | Max-turns trace was new (answered "모르겠어" before walkthrough); asked what a framework is — explained via shopping-mall-solution analogy |
| 2026-10-23 | 14/02-rewoo-plan-and-execute | 2/2 | Answered "모르겠어" on where a worker error goes (→ Solver sees it as a string) before explanation; correctly traced #E1 substitution and picked ReWOO for fixed 공구 workflow vs ReAct for 고객 응대 |
| 2026-10-23 | 14/03-reflexion-verbal-rl | 1/2 | 평가자/반성문 추적과 '외부 실패 vs 자기 실수' 구분, 오래된 중요 반성문 소실은 정확히 답함; memory rot을 저장소 소실(영속성)로 착각 |
| 2026-10-23 | 14/04-tree-of-thoughts-lats | 2/2 | 워밍업(Reflexion) 2/2. 채점 엉터리면 엉뚱한 길, c≈0이면 한 길만 파는 것을 바로 답함; 장난감 LATS가 숫자를 다 안 쓴 24를 '좋은 해'로 본 것(약한 채점 신호)을 실행으로 확인, 286 vs 152 확장 비용 대비 쓰지 말아야 한다고 정확히 판단 |
| 2026-10-24 | 14/05-self-refine-and-critic | 2/2 | 워밍업(ToT/LATS) 2/2. 자기 검토 vs 외부 검증(CRITIC)에서 CRITIC 선택, '모델이 괜찮다'만으로 멈추면 틀린 걸 못 알아채고 통과한다고 정확히 답함; Self-Refine이 4회 내내 같은 오답으로 수렴 실패하는 것을 실행으로 확인 |
| 2026-10-24 | 14/06-tool-use-and-function-calling | 2/2 | 워밍업(Self-Refine/CRITIC) 2/2. 도구 설명이 겹치면 충돌한다고 답함; 스키마·JSON 개념이 낯설어 "모르겠어"로 질문 후 설명; 질문 2에서 "3개"를 A(숫자만 뽑아 주문)로 골랐으나 돈이 나가는 도구는 엄격히 거부(B)해야 한다고 설명받음; 없는 도구는 지어내지 않고 못 한다고 말해야 한다고 정확히 답함; 장난감 코드 실행으로 enum 오류·unknown tool 오류 확인 |
| 2026-10-24 | 14/07-memory-virtual-context-memgpt | 2/2 | 워밍업(도구 사용) 2/2. 인터럽트 패턴(검색 후 응대)은 바로 답함; core vs archival 분류는 맞혔으나 "알레르기를 archival에만 두면 검색을 안 해서 놓친다"는 위험은 "모르겠어" 후 설명; 메모리 오염을 정확히 식별; 장난감 코드 실행으로 메시지가 밀려나도 core는 남고 archival 검색으로 사실을 되찾는 것을 확인 |
| 2026-10-24 | 14/08-memory-blocks-sleep-time-compute | 2/2 | 워밍업(MemGPT) 2/2. 블록 상한 도달 시 '정보를 더 못 받음'은 맞혔으나 오래된 중요 정보 소실 위험은 설명받음; 수면 에이전트가 강한 모델을 쓸 수 있는 이유(대기시간 밖)를 바로 답함; near_limit(176자) 요약 트리거를 정확히 예측; 장난감 요약기가 마침표 없는 긴 텍스트를 '.'로 날려버리는 것을 실행으로 확인; 수면 에이전트 실행 시점·모순 판단을 사람이 손으로 준 부분은 "모르겠어" 후 설명 |
| 2026-10-24 | 14/09-hybrid-memory-mem0 | 2/2 | 워밍업(Letta 블록) 2/2. 질문 유형별 저장소(배송시간→KV, 같은 건물→Graph)와 문의 응대에 최신성 가중치를 바로 답함; 통합 검색이 그래프 무효화를 후보 선정에 쓰지 않아 옛 Berlin 기록이 남는다는 점은 B로 오답 후 코드로 설명받음(무효화는 세 저장소 모두에 연결해야 함); add()에서 LLM이 자동 추출해야 하는 값(kv/graph triples, importance)은 "모르겠어" 후 설명 |
| 2026-10-25 | 14/10-skill-libraries-voyager | 2/2 | 워밍업(하이브리드 메모리) 2/2. 기존 스킬 재사용(검색 후 조합)은 맞힘; 부모가 자식의 최신 버전을 몰래 쓰는 조합 드리프트는 "모르겠어" 후 설명받았으나 코드 출력에서 직접 A로 정확히 답함; 스킬이 많아지면 비슷한 스킬 구분이 어렵다(→태그 필터)고 답함; 코드 예제가 어렵다고 해서 이후 비유·표·공구 예시 중심으로 설명 방식 변경(CLAUDE.md에 기록) |
| 2026-10-25 | 14/11-planning-htn-and-evolutionary | 2/2 | 워밍업(Voyager) 1/2: 실행 코드 저장은 맞힘, 세 구성요소는 "모르겠어" 후 신입 직원 비유로 설명. HTN(절차 엄수)·진화 검색(자동 채점기 필수) 구분을 맞힘; '문구 매력도'는 자동 채점이 어려워 진화 검색에 부적합하다는 점을 설명받음; AI 제안은 조건 검사 통과분만 채택(ChatHTN)을 정확히 답함; AI가 매기는 점수는 기준이 흔들려 채점기로 부적합하다고 정확히 답함; 코드 실행으로 AI 호출 1회 후 캐시로 0회, 진화 검색이 6세대에 점수 0 도달 확인 |
| 2026-10-25 | 14/12-anthropic-workflow-patterns | 2/2 | 워밍업(HTN/진화 검색) 2/2. 문의 분류 배분=라우팅, 공지문 작성+검수 반복=평가자-개선자를 바로 맞힘; 정해진 순서의 정산은 워크플로가 낫다고 답함; 다수결 판단=병렬, 처음 해 보는 업무=에이전트로 시작을 맞혔으나 이유는 적지 않아 설명받음(다수결은 한 번의 엉뚱한 답 방지, 새 업무는 순서를 모르니 에이전트로 탐색 후 워크플로로 고정); 코드 실행으로 다섯 패턴 합쳐 AI 호출 20번, 프레임워크 불필요 확인 |
| 2026-10-25 | 14/13-langgraph-stateful-graphs | 2/2 | 워밍업(워크플로 패턴) 2/2. 중간 실패 시 마지막 저장 지점(37단계)에서 이어서 한다고 바로 답함; 발주 진행 상황을 저장하지 않으면 중복 발주가 된다고 정확히 짚음; 발주 전 사람 승인은 정지·저장 후 재개로 해결한다고 답함; 일지에 저장할 것으로 '발주 진행 상황'을 들었고 승인 여부·외부에서 받은 값·도구 사용 기록은 설명받음; 코드 실행으로 승인 칸에서 정지 후 다음 칸부터 이어지고 접수 번호가 그대로인 것 확인 |
| 2026-10-25 | 14/14-autogen-actor-model | 3/3 | 워밍업(LangGraph) 2/2: 저장 지점부터 이어 하기, 승인 칸에서 정지 후 재개를 바로 맞힘. 한 직원이 쓰러져도 나머지는 계속 일한다(장애 격리)와 처리 못 한 메모를 보관하는 이유(사람이 확인·재처리)를 맞힘; 동시 공지는 우편함 방식을 골랐으나 이유를 '답 없으면 멈춰야 함'이라 적어 전화 방식의 단점과 우편함의 장점이 뒤바뀐 것을 바로잡아 줌; 코드 실행으로 고장 메모 1건이 dead-letter로 빠지고 나머지 3건은 정상 처리되는 것을 확인 |

## Review queue
- 14/03 Reflexion: memory rot = 저장 소실이 아니라 낡거나 틀린 반성문이 쌓여 이후 시도를 편향시키는 것 (TTL·중복제거·압축으로 대응)

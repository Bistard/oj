; ModuleID = 'seashell-compiler-output'
source_filename = "seashell-compiler-output"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.vqueue = type { %struct.llnode*, %struct.llnode* }
%struct.llnode = type { i8*, %struct.llnode* }

@.str = private unnamed_addr constant [3 x i8] c"vq\00", align 1
@.str.1 = private unnamed_addr constant [61 x i8] c"/u1/dtompkins/.seashell/projects/_A10/q1-pri-queues/vqueue.c\00", align 1
@__PRETTY_FUNCTION__.vqueue_add_back = private unnamed_addr constant [46 x i8] c"void vqueue_add_back(void *, struct vqueue *)\00", align 1
@__PRETTY_FUNCTION__.vqueue_remove_front = private unnamed_addr constant [43 x i8] c"void *vqueue_remove_front(struct vqueue *)\00", align 1
@.str.2 = private unnamed_addr constant [10 x i8] c"vq->front\00", align 1
@__PRETTY_FUNCTION__.vqueue_front = private unnamed_addr constant [48 x i8] c"const void *vqueue_front(const struct vqueue *)\00", align 1
@__PRETTY_FUNCTION__.vqueue_is_empty = private unnamed_addr constant [45 x i8] c"_Bool vqueue_is_empty(const struct vqueue *)\00", align 1
@__PRETTY_FUNCTION__.vqueue_destroy = private unnamed_addr constant [37 x i8] c"void vqueue_destroy(struct vqueue *)\00", align 1
@.str.3 = private unnamed_addr constant [20 x i8] c"vqueue_is_empty(vq)\00", align 1

; Function Attrs: noinline nounwind optnone
define %struct.vqueue* @vqueue_create() #0 {
entry:
  %vq = alloca %struct.vqueue*, align 8
  %call = call noalias i8* @malloc(i64 16) #3
  %0 = bitcast i8* %call to %struct.vqueue*
  store %struct.vqueue* %0, %struct.vqueue** %vq, align 8
  %1 = load %struct.vqueue*, %struct.vqueue** %vq, align 8
  %front = getelementptr inbounds %struct.vqueue, %struct.vqueue* %1, i32 0, i32 0
  store %struct.llnode* null, %struct.llnode** %front, align 8
  %2 = load %struct.vqueue*, %struct.vqueue** %vq, align 8
  %back = getelementptr inbounds %struct.vqueue, %struct.vqueue* %2, i32 0, i32 1
  store %struct.llnode* null, %struct.llnode** %back, align 8
  %3 = load %struct.vqueue*, %struct.vqueue** %vq, align 8
  ret %struct.vqueue* %3
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #1

; Function Attrs: noinline nounwind optnone
define void @vqueue_add_back(i8* %itm, %struct.vqueue* %vq) #0 {
entry:
  %itm.addr = alloca i8*, align 8
  %vq.addr = alloca %struct.vqueue*, align 8
  %node = alloca %struct.llnode*, align 8
  store i8* %itm, i8** %itm.addr, align 8
  store %struct.vqueue* %vq, %struct.vqueue** %vq.addr, align 8
  %0 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %tobool = icmp ne %struct.vqueue* %0, null
  br i1 %tobool, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  br label %if.end

if.else:                                          ; preds = %entry
  call void @__assert_fail(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i8* getelementptr inbounds ([61 x i8], [61 x i8]* @.str.1, i64 0, i64 0), i32 32, i8* getelementptr inbounds ([46 x i8], [46 x i8]* @__PRETTY_FUNCTION__.vqueue_add_back, i64 0, i64 0)) #4
  unreachable

if.end:                                           ; preds = %if.then
  %1 = load i8*, i8** %itm.addr, align 8
  %call = call %struct.llnode* @new_node(i8* %1, %struct.llnode* null)
  store %struct.llnode* %call, %struct.llnode** %node, align 8
  %2 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %front = getelementptr inbounds %struct.vqueue, %struct.vqueue* %2, i32 0, i32 0
  %3 = load %struct.llnode*, %struct.llnode** %front, align 8
  %cmp = icmp eq %struct.llnode* %3, null
  br i1 %cmp, label %if.then1, label %if.else3

if.then1:                                         ; preds = %if.end
  %4 = load %struct.llnode*, %struct.llnode** %node, align 8
  %5 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %front2 = getelementptr inbounds %struct.vqueue, %struct.vqueue* %5, i32 0, i32 0
  store %struct.llnode* %4, %struct.llnode** %front2, align 8
  br label %if.end4

if.else3:                                         ; preds = %if.end
  %6 = load %struct.llnode*, %struct.llnode** %node, align 8
  %7 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %back = getelementptr inbounds %struct.vqueue, %struct.vqueue* %7, i32 0, i32 1
  %8 = load %struct.llnode*, %struct.llnode** %back, align 8
  %next = getelementptr inbounds %struct.llnode, %struct.llnode* %8, i32 0, i32 1
  store %struct.llnode* %6, %struct.llnode** %next, align 8
  br label %if.end4

if.end4:                                          ; preds = %if.else3, %if.then1
  %9 = load %struct.llnode*, %struct.llnode** %node, align 8
  %10 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %back5 = getelementptr inbounds %struct.vqueue, %struct.vqueue* %10, i32 0, i32 1
  store %struct.llnode* %9, %struct.llnode** %back5, align 8
  ret void
}

; Function Attrs: noreturn nounwind
declare void @__assert_fail(i8*, i8*, i32, i8*) #2

; Function Attrs: noinline nounwind optnone
define internal %struct.llnode* @new_node(i8* %itm, %struct.llnode* %pnext) #0 {
entry:
  %itm.addr = alloca i8*, align 8
  %pnext.addr = alloca %struct.llnode*, align 8
  %node = alloca %struct.llnode*, align 8
  store i8* %itm, i8** %itm.addr, align 8
  store %struct.llnode* %pnext, %struct.llnode** %pnext.addr, align 8
  %call = call noalias i8* @malloc(i64 16) #3
  %0 = bitcast i8* %call to %struct.llnode*
  store %struct.llnode* %0, %struct.llnode** %node, align 8
  %1 = load i8*, i8** %itm.addr, align 8
  %2 = load %struct.llnode*, %struct.llnode** %node, align 8
  %item = getelementptr inbounds %struct.llnode, %struct.llnode* %2, i32 0, i32 0
  store i8* %1, i8** %item, align 8
  %3 = load %struct.llnode*, %struct.llnode** %pnext.addr, align 8
  %4 = load %struct.llnode*, %struct.llnode** %node, align 8
  %next = getelementptr inbounds %struct.llnode, %struct.llnode* %4, i32 0, i32 1
  store %struct.llnode* %3, %struct.llnode** %next, align 8
  %5 = load %struct.llnode*, %struct.llnode** %node, align 8
  ret %struct.llnode* %5
}

; Function Attrs: noinline nounwind optnone
define i8* @vqueue_remove_front(%struct.vqueue* %vq) #0 {
entry:
  %vq.addr = alloca %struct.vqueue*, align 8
  %retval5 = alloca i8*, align 8
  %old_front = alloca %struct.llnode*, align 8
  store %struct.vqueue* %vq, %struct.vqueue** %vq.addr, align 8
  %0 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %tobool = icmp ne %struct.vqueue* %0, null
  br i1 %tobool, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  br label %if.end

if.else:                                          ; preds = %entry
  call void @__assert_fail(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i8* getelementptr inbounds ([61 x i8], [61 x i8]* @.str.1, i64 0, i64 0), i32 43, i8* getelementptr inbounds ([43 x i8], [43 x i8]* @__PRETTY_FUNCTION__.vqueue_remove_front, i64 0, i64 0)) #4
  unreachable

if.end:                                           ; preds = %if.then
  %1 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %front = getelementptr inbounds %struct.vqueue, %struct.vqueue* %1, i32 0, i32 0
  %2 = load %struct.llnode*, %struct.llnode** %front, align 8
  %tobool1 = icmp ne %struct.llnode* %2, null
  br i1 %tobool1, label %if.then2, label %if.else3

if.then2:                                         ; preds = %if.end
  br label %if.end4

if.else3:                                         ; preds = %if.end
  call void @__assert_fail(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @.str.2, i64 0, i64 0), i8* getelementptr inbounds ([61 x i8], [61 x i8]* @.str.1, i64 0, i64 0), i32 44, i8* getelementptr inbounds ([43 x i8], [43 x i8]* @__PRETTY_FUNCTION__.vqueue_remove_front, i64 0, i64 0)) #4
  unreachable

if.end4:                                          ; preds = %if.then2
  %3 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %front6 = getelementptr inbounds %struct.vqueue, %struct.vqueue* %3, i32 0, i32 0
  %4 = load %struct.llnode*, %struct.llnode** %front6, align 8
  %item = getelementptr inbounds %struct.llnode, %struct.llnode* %4, i32 0, i32 0
  %5 = load i8*, i8** %item, align 8
  store i8* %5, i8** %retval5, align 8
  %6 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %front7 = getelementptr inbounds %struct.vqueue, %struct.vqueue* %6, i32 0, i32 0
  %7 = load %struct.llnode*, %struct.llnode** %front7, align 8
  store %struct.llnode* %7, %struct.llnode** %old_front, align 8
  %8 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %front8 = getelementptr inbounds %struct.vqueue, %struct.vqueue* %8, i32 0, i32 0
  %9 = load %struct.llnode*, %struct.llnode** %front8, align 8
  %next = getelementptr inbounds %struct.llnode, %struct.llnode* %9, i32 0, i32 1
  %10 = load %struct.llnode*, %struct.llnode** %next, align 8
  %11 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %front9 = getelementptr inbounds %struct.vqueue, %struct.vqueue* %11, i32 0, i32 0
  store %struct.llnode* %10, %struct.llnode** %front9, align 8
  %12 = load %struct.llnode*, %struct.llnode** %old_front, align 8
  %13 = bitcast %struct.llnode* %12 to i8*
  call void @free(i8* %13) #3
  %14 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %front10 = getelementptr inbounds %struct.vqueue, %struct.vqueue* %14, i32 0, i32 0
  %15 = load %struct.llnode*, %struct.llnode** %front10, align 8
  %cmp = icmp eq %struct.llnode* %15, null
  br i1 %cmp, label %if.then11, label %if.end12

if.then11:                                        ; preds = %if.end4
  %16 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %back = getelementptr inbounds %struct.vqueue, %struct.vqueue* %16, i32 0, i32 1
  store %struct.llnode* null, %struct.llnode** %back, align 8
  br label %if.end12

if.end12:                                         ; preds = %if.then11, %if.end4
  %17 = load i8*, i8** %retval5, align 8
  ret i8* %17
}

; Function Attrs: nounwind
declare void @free(i8*) #1

; Function Attrs: noinline nounwind optnone
define i8* @vqueue_front(%struct.vqueue* %vq) #0 {
entry:
  %vq.addr = alloca %struct.vqueue*, align 8
  store %struct.vqueue* %vq, %struct.vqueue** %vq.addr, align 8
  %0 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %tobool = icmp ne %struct.vqueue* %0, null
  br i1 %tobool, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  br label %if.end

if.else:                                          ; preds = %entry
  call void @__assert_fail(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i8* getelementptr inbounds ([61 x i8], [61 x i8]* @.str.1, i64 0, i64 0), i32 57, i8* getelementptr inbounds ([48 x i8], [48 x i8]* @__PRETTY_FUNCTION__.vqueue_front, i64 0, i64 0)) #4
  unreachable

if.end:                                           ; preds = %if.then
  %1 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %front = getelementptr inbounds %struct.vqueue, %struct.vqueue* %1, i32 0, i32 0
  %2 = load %struct.llnode*, %struct.llnode** %front, align 8
  %tobool1 = icmp ne %struct.llnode* %2, null
  br i1 %tobool1, label %if.then2, label %if.else3

if.then2:                                         ; preds = %if.end
  br label %if.end4

if.else3:                                         ; preds = %if.end
  call void @__assert_fail(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @.str.2, i64 0, i64 0), i8* getelementptr inbounds ([61 x i8], [61 x i8]* @.str.1, i64 0, i64 0), i32 58, i8* getelementptr inbounds ([48 x i8], [48 x i8]* @__PRETTY_FUNCTION__.vqueue_front, i64 0, i64 0)) #4
  unreachable

if.end4:                                          ; preds = %if.then2
  %3 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %front5 = getelementptr inbounds %struct.vqueue, %struct.vqueue* %3, i32 0, i32 0
  %4 = load %struct.llnode*, %struct.llnode** %front5, align 8
  %item = getelementptr inbounds %struct.llnode, %struct.llnode* %4, i32 0, i32 0
  %5 = load i8*, i8** %item, align 8
  ret i8* %5
}

; Function Attrs: noinline nounwind optnone
define zeroext i1 @vqueue_is_empty(%struct.vqueue* %vq) #0 {
entry:
  %vq.addr = alloca %struct.vqueue*, align 8
  store %struct.vqueue* %vq, %struct.vqueue** %vq.addr, align 8
  %0 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %tobool = icmp ne %struct.vqueue* %0, null
  br i1 %tobool, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  br label %if.end

if.else:                                          ; preds = %entry
  call void @__assert_fail(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i8* getelementptr inbounds ([61 x i8], [61 x i8]* @.str.1, i64 0, i64 0), i32 64, i8* getelementptr inbounds ([45 x i8], [45 x i8]* @__PRETTY_FUNCTION__.vqueue_is_empty, i64 0, i64 0)) #4
  unreachable

if.end:                                           ; preds = %if.then
  %1 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %front = getelementptr inbounds %struct.vqueue, %struct.vqueue* %1, i32 0, i32 0
  %2 = load %struct.llnode*, %struct.llnode** %front, align 8
  %cmp = icmp eq %struct.llnode* %2, null
  ret i1 %cmp
}

; Function Attrs: noinline nounwind optnone
define void @vqueue_destroy(%struct.vqueue* %vq) #0 {
entry:
  %vq.addr = alloca %struct.vqueue*, align 8
  store %struct.vqueue* %vq, %struct.vqueue** %vq.addr, align 8
  %0 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %tobool = icmp ne %struct.vqueue* %0, null
  br i1 %tobool, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  br label %if.end

if.else:                                          ; preds = %entry
  call void @__assert_fail(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i8* getelementptr inbounds ([61 x i8], [61 x i8]* @.str.1, i64 0, i64 0), i32 70, i8* getelementptr inbounds ([37 x i8], [37 x i8]* @__PRETTY_FUNCTION__.vqueue_destroy, i64 0, i64 0)) #4
  unreachable

if.end:                                           ; preds = %if.then
  %1 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %call = call zeroext i1 @vqueue_is_empty(%struct.vqueue* %1)
  br i1 %call, label %if.then1, label %if.else2

if.then1:                                         ; preds = %if.end
  br label %if.end3

if.else2:                                         ; preds = %if.end
  call void @__assert_fail(i8* getelementptr inbounds ([20 x i8], [20 x i8]* @.str.3, i64 0, i64 0), i8* getelementptr inbounds ([61 x i8], [61 x i8]* @.str.1, i64 0, i64 0), i32 71, i8* getelementptr inbounds ([37 x i8], [37 x i8]* @__PRETTY_FUNCTION__.vqueue_destroy, i64 0, i64 0)) #4
  unreachable

if.end3:                                          ; preds = %if.then1
  %2 = load %struct.vqueue*, %struct.vqueue** %vq.addr, align 8
  %3 = bitcast %struct.vqueue* %2 to i8*
  call void @free(i8* %3) #3
  ret void
}

attributes #0 = { noinline nounwind optnone "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+cx8,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+cx8,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noreturn nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+cx8,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }
attributes #4 = { noreturn nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"clang version 9.0.1 (https://github.com/llvm/llvm-project.git c1a0a213378a458fbea1a5c77b315c7dce08fd05)"}
!1 = !{i32 1, !"wchar_size", i32 4}

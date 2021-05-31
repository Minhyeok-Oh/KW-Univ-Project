<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt"%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!doctype html>
<html>

<head>
<title>천둥마켓</title>
<style>
table {
	table-layout: fixed;
}

.container {
	
}

th, td {
	border: 1px solid black;
	text-align: center;
}

* {
	box-sizing: border-box;
}

.container {
	border: 1px solid black;
}

.container>* {
	border: 1px solid black;
}

.container>.content>* {
	border: 1px solid black;
}

.container .content {
	padding-left: 200px;
	padding-right: 150px;
	overflow: hidden;
}

.container .content>* {
	float: left;
	padding-bottom: 2500px;
	margin-bottom: -2500px;
}

.container .content main {
	width: 100%;
	position: relative;
}

.container .content nav {
	width: 200px;
	margin-left: -100%;
	left: -200px;
	position: relative;
}

.container .content aside {
	width: 150px;
	margin-right: -150px;
}

.container footer {
	clear: both;
}

@media ( max-width :599px) {
	.container .content {
		padding-left: 0;
		padding-right: 0;
		overflow: visible;
	}
	.container .content>* {
		float: none;
		padding-bottom: 0;
		margin-bottom: 0;
	}
	.container .content main {
		width: 100%;
	}
	.container .content nav {
		width: auto;
		margin-left: 0;
		left: 0;
		position: relative;
	}
	.container .content aside {
		width: auto;
		margin-right: 0;
	}
}
</style>
<script type="text/javascript">
	function modifycheck() {
		var input = document.getElementById("password").value;
		var passwd = '<c:out value="${view.passwd}"/>';
		var bno = '<c:out value="${view.bno}"/>';
		if (input == passwd) {
			document.location.href = '/modify?bno=' + bno;
		} else {
			alert("비밀번호가 일치하지 않습니다.");
		}
	}
	function deletecheck() {
		var input = document.getElementById("password").value;
		var passwd = '<c:out value="${view.passwd}"/>';
		var bno = '<c:out value="${view.bno}"/>';
		if (input == passwd) {
			document.location.href = '/delete?bno=' + bno;
		} else {
			alert("비밀번호가 일치하지 않습니다.");
		}
	}
	function replymodifycheck(passwd,rno){
		var input = document.getElementById(rno).value;
		var bno = '<c:out value="${view.bno}"/>';
		if(passwd == input){
			document.location.href='/replydelete?rno=' +rno+'&bno='+bno;
		}
		else{
			alert("비밀번호가 일치하지 않습니다.");
		}
	}
</script>
</head>

<body>
	<div class="container">
		<header>
			<h3>
				<a href="/">천둥마켓</a>
			</h3>
		</header>
		<section class="content">
			<main>
			<p style="border: 1px solid black">PostNumber: ${view.bno}</p>
			<div style="position: relative; overflow: auto; height: auto;">
				<div
					style="width: 30%; float: left; box-sizing: border-box; border: 1px solid black; height: 300px">
					<img src="/resources/img/${file.stored_file_name}"
						style="max-width: 100%" ; height:auto; alt="오류">
				</div>
				<div
					style="width: 70%; float: right; box-sizing: border-box; border: 1px solid black; height: 300px">
					<p>
						<b>작성자</b> ${view.writer}&emsp;&emsp;&emsp;<b>작성일</b>
						<fmt:formatDate value="${view.regDate}" pattern="yyyy.MM.dd HH:mm" />
						&emsp;&emsp;&emsp;<b>조회수</b> ${view.viewCnt}
					</p>
					<p>
						<b>상품설명</b>
					</p>
					<p style="height: 70px;">${view.description }</p>
					<p>
						<b>가격</b>
					</p>
					<p>
						<b><fmt:formatNumber type="number" maxFractionDigits="3"
								value="${view.price}" />￦</b>
					</p>
				</div>

				<div
					style="box-sizing: border-box; border: 1px solid black; height: 300px">
					<p>댓글(${countReply})</p>
					<c:forEach items="${replyList}" var="replyList">
						<div>
							<p>
							<div style="display: inline; float: right">
								<input type="text" id="${replyList.rno}" value="비밀번호"
									onfocus="this.value='';" />
								<button
									onClick="replymodifycheck('${replyList.passwd}',${replyList.rno});">수정</button>
							</div>
							<b>작성자</b> ${replyList.writer}
							</p>
							<p>${replyList.content}
								(
								<fmt:formatDate value="${replyList.regdate}"
									pattern="yyyy.MM.dd HH:mm" />
								)
							</p>
						</div>
					</c:forEach>
					<form method="post" style="border: 1px solid black;">
						<table>
							<tr>

								<td><c:choose>
										<c:when test="${empty vo.content}">
											<input type="text" name="writer" value="이름"
												onfocus="this.value='';" required />
										</c:when>
										<c:otherwise>
											<input type="text" name="writer" value="${vo.writer}"
												required />
										</c:otherwise>
									</c:choose></td>

								<td rowspan="2"><textarea
										style="height: 50px; width: 600px;" type="text" name="content"
										required />${vo.content}</textarea></td>
								<td rowspan="2"><button style="height: 50px; width: 50px;"
										type="submit">등록</button>
							</tr>
							<tr>
								<td><c:choose>
										<c:when test="${empty vo.content}">
											<input type="text" name="passwd" value="비밀번호"
												onfocus="this.value='';" required />
										</c:when>
										<c:otherwise>
											<input type="text" name="passwd" value="${vo.passwd}"
												onfocus="this.value='';" required />
										</c:otherwise>
									</c:choose></td>
							</tr>
						</table>
					</form>
					<div style="position: absolute; right: 0;">
						<input style="height: 25px;" type="text" id="password"
							value="게시글 비밀번호" onfocus="this.value='';" />&nbsp;
						<button style="height: 25px;" type="button"
							onClick="modifycheck();">게시글 수정</button>
						&nbsp;
						<button style="height: 25px;" type="button"
							onClick="deletecheck();">게시글 삭제</button>
					</div>
				</div>

			</div>

			</main>
			<nav>
				<div style="position: relative; height: 3000px;">
					<div style="border: 1px solid black">카테고리</div>
					<div>
						<ul>
							<li><a href="/">ALL</a></li>
							<li><a href="/Books">Books</a></li>
							<li><a href="/Accessory">Accessory</a></li>
							<li><a href="/Clothes">Clothes</a></li>
							<li><a href="/Stationery">Stationery</a></li>
							<li><a href="/Etc">etc.</a></li>
						</ul>

					</div>
					<div style="position: relative; bottom: 0px; text-align: center;">
						<button type="button" onClick="location.href='/write'">글쓰기</button>
					</div>
				</div>
			</nav>
			<aside></aside>


		</section>
	</div>
</body>

</html>
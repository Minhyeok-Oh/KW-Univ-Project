<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!doctype html>
<html>

<head>
<title>천둥마켓</title>
<style>
body {
	margin: 0;
}

html, body {
	height: 100%;
}

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
			<table width="800px"
				style="border-collapse: collapse; margin-left: auto; margin-right: auto; margin-top: 30px; border: 1px solid black">
				<th colspan="4"
					style="height: 40px; vertical-align: top; text-align: left;">Clothes</th>
				<c:forEach items="${list}" var="list">
					<c:if test="${list.state ne 3}">
						<tr>
							<th rowspan="3"><c:forEach items="${fileList}"
									var="fileList">
									<c:if test="${fileList.bno eq list.bno}">
										<img src="/resources/img/${fileList.stored_file_name}"
											style="max-width: 100%" ; height:auto; alt="오류">
									</c:if>
								</c:forEach></th>
							<td style="height: 20px;">상품설명</td>
							<td>가격</td>
							<td rowspan="2">PostNumber: ${list.bno}<br>이름:${list.writer}<br>조회수:${list.viewCnt}<br>작성일:<fmt:formatDate
									value="${list.regDate}" pattern="yyyy.MM.dd" />
								</div>
							</td>
						</tr>
						<tr>
							<td rowspan="2" style="height: 100px;">${list.description}</td>
							<td rowspan="2"><fmt:formatNumber type="number"
									maxFractionDigits="3" value="${list.price}" />￦</td>
						</tr>
						<tr>
							<td style="height: 40px;"><button type="button"
									onClick="location.href='/view?bno=${list.bno}'">
									<c:choose>
										<c:when test="${list.state eq 1}">판매중</c:when>
										<c:when test="${list.state eq 2}">예약중</c:when>
										<c:when test="${list.state eq 3}">판매완료</c:when>
									</c:choose>
								</button></td>
						</tr>
					</c:if>
				</c:forEach>
				<c:forEach items="${list}" var="list">
					<c:if test="${list.state eq 3}">
						<tr>
							<th rowspan="3"><c:forEach items="${fileList}"
									var="fileList">
									<c:if test="${fileList.bno eq list.bno}">
										<img src="/resources/img/${fileList.stored_file_name}"
											style="max-width: 100%" ; height:auto; alt="오류">
									</c:if>
								</c:forEach></th>
							<td style="height: 20px;">상품설명</td>
							<td>가격</td>
							<td rowspan="2">PostNumber: ${list.bno}<br>이름:${list.writer}<br>조회수:${list.viewCnt}<br>작성일:<fmt:formatDate
									value="${list.regDate}" pattern="yyyy.MM.dd" />
								</div>
							</td>
						</tr>
						<tr>
							<td rowspan="2" style="height: 100px;">${list.description}</td>
							<td rowspan="2"><fmt:formatNumber type="number"
									maxFractionDigits="3" value="${list.price}" />￦</td>
						</tr>
						<tr>
							<td style="height: 40px;"><button type="button"
									onClick="location.href='/view?bno=${list.bno}'">
									<c:choose>
										<c:when test="${list.state eq 1}">판매중</c:when>
										<c:when test="${list.state eq 2}">예약중</c:when>
										<c:when test="${list.state eq 3}">판매완료</c:when>
									</c:choose>
								</button></td>
						</tr>
					</c:if>
				</c:forEach>
			</table>
			</main>
			<nav>
				<div style="border: 1px solid black">카테고리</div>
				<ul>
					<li><a href="/">ALL</a></li>
					<li><a href="/Books">Books</a></li>
					<li><a href="/Accessory">Accessory</a></li>
					<li><a href="/Clothes"><b>Clothes</b></a></li>
					<li><a href="/Stationery">Stationery</a></li>
					<li><a href="/Etc">etc.</a></li>
				</ul>
				<div style="position: relative; bottom: 0px; text-align: center;">
					<c:choose>
						<c:when test="${CurNum eq 1}">
							<span><a href="/Clothes?num=${CurNum}">&lt;&lt;</a></span>
						</c:when>
						<c:otherwise>
							<span><a href="/Clothes?num=${CurNum-1}">&lt;&lt;</a></span>
						</c:otherwise>
					</c:choose>
					<c:forEach begin="${StartNum}" end="${EndNum}" var="num">
						<c:choose>
							<c:when test="${CurNum eq num}">
								<span> <a href="/Clothes?num=${num}"><b>${num}</b></a>
								</span>
							</c:when>
							<c:when test="${num le pageNum}">
								<span> <a href="/Clothes?num=${num}">${num}</a>
								</span>
							</c:when>
						</c:choose>
					</c:forEach>
					<c:choose>
						<c:when test="${CurNum eq pageNum}">
							<span><a href="/Clothes?num=${CurNum}">&gt;&gt;</a></span>
						</c:when>
						<c:otherwise>
							<span><a href="/Clothes?num=${CurNum+1}">&gt;&gt;</a></span>
						</c:otherwise>
					</c:choose>
				</div>
				<div style="position: relative; bottom: 0px; text-align: center;">
					<button type="button" onClick="location.href='/write'">글쓰기</button>
				</div>
			</nav>
			<aside></aside>
		</section>
	</div>
</body>

</html>
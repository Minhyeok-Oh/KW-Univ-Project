<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
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
		<section class="content" style="height: 100vh">
			<main>
			<p style="height: 10px">게시글 작성</p>

			<form method="post" name="userinput" enctype="multipart/form-data"
				style="border: 1px solid black;">

				<label>닉네임</label> <input type="text" name="writer" required/><br /> <label>비밀번호</label>
				<input type="password" name="passwd" required/><label>카테고리</label><select
					name="category" required>
					<option value="Books">Books</option>
					<option value="Accessory">Accessory</option>
					<option value="Clothes">Clothes</option>
					<option value="Stationery">Stationery</option>
					<option value="Etc">etc.</option>
				</select><br /> <label>내용</label>
				<textarea cols="50" rows="5" name="description" required></textarea>
				<br> <label>가격</label><input type="text" name="price" required/>￦<br />
				<input type="file" name="file" required><br> <label><input
					type="radio" name="state" value="1" required> 판매중</label> <label><input
					type="radio" name="state" value="2"> 예약중</label><label><input
					type="radio" name="state" value="3"> 판매완료</label>
				<button type="submit">등록</button>

			</form>
			</p>
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
					<div style="position: relative; bottom: 0px; text-align:center;">
						<button type="button" onClick="location.href='/write'">글쓰기</button>
					</div>
				</div>
			</nav>
			<aside></aside>
		</section>
	</div>
</body>

</html>
package com.project2.dao;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.inject.Inject;

import org.apache.ibatis.session.SqlSession;
import org.springframework.stereotype.Repository;

import com.project2.domain.BoardVO;

@Repository // create this class to bean object of root container
public class BoardDAOImpl implements BoardDAO {

	@Inject // find bean object for same name
	private SqlSession sql; // SqlSession for database language

	private static String namespace = "com.project2.mappers.board";
	// namespace mappers

	@Override
	public List<BoardVO> list(String category, int displayPost, int postNum) throws Exception {
		BoardVO vo = new BoardVO(); // make vo object
		vo.setCategory(category); // category setting
		vo.setPrice(displayPost); // price setting
		vo.setState(postNum); // state setting
		return sql.selectList(namespace + ".list", vo); // select list for category
	}

	@Override
	public void write(BoardVO vo) throws Exception {
		sql.insert(namespace + ".write", vo); // insert post information to database
	}

	public BoardVO view(int bno) throws Exception {
		return sql.selectOne(namespace + ".view", bno); // select one post information for post number
	}

	public void modify(BoardVO vo) throws Exception {
		sql.update(namespace + ".modify", vo); // update post information of database
	}

	public void delete(int bno) throws Exception {
		sql.delete(namespace + ".delete", bno); // delete post information of database
	}

	public int count() throws Exception {
		return sql.selectOne(namespace + ".count"); // the number of post
	}

	public int countCate(String category) throws Exception {
		return sql.selectOne(namespace + ".countCate", category); // the number of post for category
	}

	public List<BoardVO> listPage(int displayPost, int postNum) throws Exception {
		HashMap<String, Integer> data = new HashMap<String, Integer>();

		data.put("displayPost", displayPost);
		data.put("postNum", postNum);

		return sql.selectList(namespace + ".listPage", data); // select post information list
	}

	public void updateviewCnt(int bno) throws Exception {
		sql.update(namespace + ".updateviewCnt", bno); // update post information for post number
	}

	@Override
	public void insertFile(Map<String, Object> map) throws Exception {
		// TODO Auto-generated method stub
		sql.insert(namespace + ".insertFile", map); // insert file information
	}

	@Override
	public Map<String, Object> selectFile(int bno) throws Exception {
		// TODO Auto-generated method stub
		return sql.selectOne(namespace + ".selectFile", bno); // select one file information for post number
	}

	@Override
	public void deleteFile(int file_no) throws Exception {
		// TODO Auto-generated method stub
		sql.delete(namespace + ".deleteFile", file_no); // delete file information of database for file number
	}

}
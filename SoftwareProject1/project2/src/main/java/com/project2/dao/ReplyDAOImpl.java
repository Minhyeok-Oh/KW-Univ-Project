package com.project2.dao;

import java.util.List;

import javax.inject.Inject;

import org.apache.ibatis.session.SqlSession;
import org.springframework.stereotype.Repository;

import com.project2.domain.ReplyVO;

@Repository // create this class to bean object of root container
public class ReplyDAOImpl implements ReplyDAO {
	@Inject // find bean object for same name
	private SqlSession sql; // SqlSession for database language
	// namespace mappers
	private static String namespace = "com.project2.mappers.reply";

	@Override
	public List<ReplyVO> readReply(int bno) throws Exception {
		// TODO Auto-generated method stub
		return sql.selectList(namespace + ".replyList", bno); // select comment list for post number
	}

	@Override
	public int countReply(int bno) throws Exception {

		return sql.selectOne(namespace + ".replyCount", bno); // the number of comment for post number
	}

	@Override
	public void writeReply(ReplyVO vo) throws Exception {
		// TODO Auto-generated method stub
		sql.insert(namespace + ".writeReply", vo); // insert comment information to database
	}

	@Override
	public ReplyVO viewReply(int rno) throws Exception {
		// TODO Auto-generated method stub
		return sql.selectOne(namespace + ".viewReply", rno); // select one comment for comment number
	}

	@Override
	public void deleteReply(int rno) throws Exception {
		// TODO Auto-generated method stub
		sql.delete(namespace + ".deleteReply", rno); // delete comment for comment number
	}

}
